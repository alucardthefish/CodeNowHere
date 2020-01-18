//******************************************************************************************
// File: CodeNowHere.cpp
// Author: Sergio Ortiz Paz
// Created: Mon Dec 23 22:18:25 2019
// Description: Classes in charge of process the input data from console and showing output
//******************************************************************************************
#include "../headers/CodeNowHere.h"

CodeNowHere::CodeNowHere() {
    dataPath = LibConstants::LOCAL_DATA;
    #ifdef DATA_LOCATION
        cout << "test es: " << DATA_LOCATION << endl;
        dataPath = DATA_LOCATION;
    #endif
    blowExtensions();
}


void CodeNowHere::blowExtensions() {
    
    // Parsing the extensions with their corresponding in-line comment syntax
    ifstream file;

    string fileOfCommentsByExtension =  dataPath + "InlineComments.txt";

    try {
        file.open(fileOfCommentsByExtension);

        while(file) {
            string extRead;
			string commentRead;
			
			string extensions;
			getline(file, extensions, ':');
			stringstream extStreams(extensions);

			file >> commentRead;
			file.get();
            
			while(getline(extStreams, extRead, ' ')) {
				commentMap[extRead] = commentRead;
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


void CodeNowHere::captureConsoleInput(int argc, char * argv[]) {
    // Capture input from console and process it
    author = "";
    description = "";
    fileName = argv[1];
    for (int i = 0; i < argc; i++) {
        string param = argv[i];
        if (param == "-a" || param == "--author"){
            // Author param specified
            if (argc == 2) {
                cout << "Author option requires argument after (-a | --author)" << endl;
            } else {
                author = argv[i+1];
            }

        } else if (param == "-d" || param == "--desc") {
            // Description param specified
            if (argc == 2) {
                cout << "Description option requires argument after (-d | --desc)" << endl;
            } else {
                description = argv[i+1];
            }
        }
    }
}

string CodeNowHere::getExtension(string fileName) {
    string ext;
    size_t dotPosition = fileName.find(".");
    ext = fileName.substr(dotPosition);
    return ext;
}

string CodeNowHere::getNameOfFile(string fileName) {
    string name;
	size_t dotPosition = fileName.find(".");
	name = fileName.substr(0, dotPosition);
    return name;
}

void CodeNowHere::addCommentHeader() {
    ofstream file;
    file.open(fileName);
    file << comment << " **************************************************************************** " << endl;
    file << comment << " File: " << fileName << endl;
    file << comment << " Author: " << author << endl;
    file << comment << " Created: " << dateOfCreation;
    file << comment << " Description: " << description << endl;
    file << comment << " **************************************************************************** " << endl;
    addMainTmplate(file, fileName);
    file.close();
}

string CodeNowHere::getLang(string fileName) {
    // Getting the extension of the file
	string ext = getExtension(fileName);
    ifstream file;
    string fileOfLanguages = dataPath + "lang.dat";
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


void CodeNowHere::replaceClassName(string& className, string filename) {
	const string CLASSNAMETMPL = "HelloWorld";
	int si_ze = CLASSNAMETMPL.length();
	string namefile = getNameOfFile(filename);
	size_t poss = className.find(CLASSNAMETMPL);
	if (poss != string::npos) {
		className.replace(poss, si_ze, namefile);
	}
}


void CodeNowHere::addMainTmplate(ofstream& codeFile, string fileName) {
    ifstream file;
	string lang = getLang(fileName);
    string fileOfFunction = dataPath;
	fileOfFunction += lang;
	fileOfFunction += ".tpl";

    try {
        file.open(fileOfFunction);

        codeFile << endl << endl;
		
        while(file) {

			string line = "";
			getline(file, line);
			replaceClassName(line, fileName);

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


void CodeNowHere::createCode() {
    Helper helper;
    // file name validation
    if (helper.validateFileName(fileName)) {
        string ext = getExtension(fileName);
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
        comment = commentMap[ext];
        
        time_t now = time(0);
        char* dt = ctime(&now);
        dateOfCreation = string(dt);

        if (comment.empty()) {
            cout << "The program does not recognize this extension by now. Do you want to add a header comment to this unknown file (y/n): ";
            string decision = "";
            cin >> decision;
            std::transform(decision.begin(), decision.end(), decision.begin(), ::tolower);
            if (decision == "y" || decision == "yes") {
                cout << "Enter the in-line comment syntax for this type of programming language: ";
                cin.clear();
                cin.ignore(10000, '\n');
                getline(cin, comment);
                while(comment.empty()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "try again: ";
                    getline(cin, comment);

                }
                if(!comment.empty()){
                    addCommentHeader();
                }
            } else {
                ofstream file;
                file.open(fileName);
                file.close();
            }
        } else {
            addCommentHeader();
        }
    } else {
        cout << fileName << " is not a valid file name. File name must be in this form 'filename.ext'" << endl;
    }

}

Helper::Helper() {
    version = "1.0";
    blowMessages();
}

void Helper::blowMessages() {
    messages["badInput"] = "Some option is missing or some parameters are invalid! \nCheck help typing cnw --help | -h";
    static const char USAGE[] =
    R"(CodeNowHere (cnh).

        Usage:
            cnh (<file name with extension>) [-option <argument>]...
            cnh (-h | --help)
            cnh --version
        
        Options:
            -h --help       Show this screen.
            --version       Show version.
            -a --author     Specify the author of the code.
            -d --desc       Specify a brief description of the file.
    )";
    messages["usage"] = string(USAGE);
}

string Helper::getBadInput(){
    return messages["badInput"];
}

string Helper::getUsage(){
    return messages["usage"];
}

string Helper::getVersion(){
    return version;
}

bool Helper::validateFileName(string fileName)
// validateFileName: receives the file name string and evaluates if its a correct format
// returns: true if is correct false otherwise.
{
    bool result = false;
    try {
        regex re("^[A-Za-z0-9_-]*(\\.)([A-Za-z0-9]*)$");
        smatch match;
        result = regex_search(fileName, match, re) && (match.size() > 1);
    } catch (regex_error& e) {
        cout << "ERROR: syntax error in the regular expresion" << endl;
    }
    return result;
}
