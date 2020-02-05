// **************************************************************************** 
// File: ICommandBehavior.cpp 
// Author: Sergio Ortiz Paz 
// Created: Mon Feb  3 18:25:35 2020 
// Description: Implement abstract class that represent a command behavior 
// **************************************************************************** 

#include "../headers/ICommandBehavior.h"

using namespace std;


void ICommandBehavior::CreateCommentHeader() {
    ofstream file;
    file.open(fileName);
    file << comment << " **************************************************************************** " << commentClosureOpt << endl;
    file << comment << " File: " << fileName << " " << commentClosureOpt << endl;
    file << comment << " Author: " << author << " " << commentClosureOpt << endl;
    file << comment << " Created: " << dateOfCreation << " " << commentClosureOpt << endl;
    file << comment << " Description: " << description << " " << commentClosureOpt << endl;
    file << comment << " **************************************************************************** " << commentClosureOpt << endl;
    CreateMainTemplate(file, fileName);
    file.close();
}

void ICommandBehavior::CreateMainTemplate(ofstream& codeFile, string fileName) {
    ifstream file;
	string lang = getLang(fileName);
    string fileOfFunction = Helper::getDataPath();
	fileOfFunction += lang;
	fileOfFunction += ".tpl";

    try {
        file.open(fileOfFunction);

        codeFile << endl << endl;
		
        while(file) {

			string line = "";
			getline(file, line);
			Helper::replaceClassName(line, fileName);

			if (line == "") {
				codeFile << endl;
			} else {
				codeFile << line << endl;
			}

            if(!file) {
                break;
            }
        }
    } catch(const ifstream::failure& e) {
        cout << "There was a problem with the extension provider" << endl;
    }

    file.close();
}

string ICommandBehavior::getLang(string fileName) {
    // Getting the extension of the file
	string ext = Helper::getExtension(fileName);
    ifstream file;
    string fileOfLanguages = Helper::getDataPath() + "lang.dat";
	string language = "";

    try {
        file.open(fileOfLanguages);

        while(file) {
            string extRead;
			string commentRead;
			bool found = false;
			
			string extensions;
			getline(file, extensions, ':');
			stringstream extStreams(extensions);

			file >> commentRead;
			file.get();
            
			while(getline(extStreams, extRead, ' ')) {
				if (extRead == ext) {
					found = true;
					language = commentRead;
					break;
				}
			}

            if(!file || found) {
                break;
            }
        }
    } catch(const ifstream::failure& e) {
        cout << "There was a problem with the extension provider" << endl;
    }

    file.close();
	return language;
}

void ICommandBehavior::blowCommentByExtensions(string ext) {

    // Parsing the extensions with their corresponding in-line comment syntax
    ifstream file;

    string fileOfCommentsByExtension =  Helper::getDataPath() + "InlineComments.txt";

    try {
        file.open(fileOfCommentsByExtension);
        bool extWasFound = false;
        while(file && !extWasFound) {
            string extRead;
			string commentRead;
            string commentOptRead;
			
			string extensions;
			getline(file, extensions, ':');
			stringstream extStreams(extensions);

			file >> commentRead >> commentOptRead;
			file.get();
            
			while(getline(extStreams, extRead, ' ')) {
				
                if (ext == extRead) {
                    comment = commentRead;
                    commentClosureOpt = commentOptRead;
                    if (commentOptRead == "{}") {
                        commentClosureOpt = "";
                    }
                    extWasFound = true;
                    break;
                }
			}

            if(!file) {
                break;
            }
        }
    } catch(const ifstream::failure& e) {
        cout << "There was a problem with the extension provider" << endl;
    }

    file.close();
}

void ICommandBehavior::feed(std::map<std::string, docopt::value> args) {
    fileName = args["<filename>"].asString();
    author = (!args["--author"].asStringList().empty()) ? args["--author"].asStringList().at(0) : "";
    description = (!args["--desc"].asStringList().empty()) ? args["--desc"].asStringList().at(0) : "";
}

