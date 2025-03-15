// ****************************************************************************
// File: ICommandBehavior.cpp
// Author: Sergio Ortiz Paz
// Created: Mon Feb  3 18:25:35 2020
// Description: Implement abstract class that represents a command behavior
// ****************************************************************************

#include "../headers/ICommandBehavior.h"
#include <cstring>

using namespace std;


fstream ICommandBehavior::startUsingFile() {
    fstream file(fileName, ios::in | ios::out | ios::app);
    return file;
}

void ICommandBehavior::CreateProlog() {
    fstream file = startUsingFile();
    if (!file.is_open()) {
        cout << "Error while opening file" << endl;
    } else {
        string lang = getLang(fileName);
        if (lang == "html") {
            file << "<!DOCTYPE html>" << endl;
        } else if (lang == "xml") {
            file << "<?xml version='1.0' encoding='UTF-8'?>" << endl;
        } else if (lang == "php") {
            file << "<?php" << endl;
        }
    }
    file.close();
}

void ICommandBehavior::CreateCommentHeader(int headerLength = 110) {
    fstream file = startUsingFile();
    if (!file.is_open())
    {
        cout << "Error while opening file" << endl;
    } else
    {
        RegisterDateOfCreation();
        file << comment << " " << nTimesThisString("*", headerLength) << " " << commentClosureOpt << endl;
        file << comment << includeHeaderAttribute("File:", fileName, headerLength) << " " << commentClosureOpt << endl;
        file << comment << includeHeaderAttribute("Author:", author, headerLength) << " " << commentClosureOpt << endl;
        file << comment << includeHeaderAttribute("Created:", dateOfCreation, headerLength) << " " << commentClosureOpt << endl;
        if (hasCopyRight)
        {
            string text = to_string(year);
            text += " " + author + ". All rights reserved. ";
            file << comment << includeHeaderAttribute("Copyright (c)", text, headerLength) << " " << commentClosureOpt << endl;
        }
        file << comment << includeHeaderAttribute("Description:", description, headerLength)  << " " << commentClosureOpt << endl;
        file << comment << " " << nTimesThisString("*", headerLength) << " " << commentClosureOpt << endl;
    }
    file.close();
}

void ICommandBehavior::CreateMainTemplate() {
    fstream file = startUsingFile();
    if (!file.is_open()) {
        cout << "Error while opening file" << endl;
    } else {
        ifstream templateFile;
        string lang = getLang(fileName);
        string fileOfFunction = Helper::getDataPath();
        fileOfFunction += lang;
        fileOfFunction += ".tpl";

        try {
            templateFile.open(fileOfFunction);

            file << endl << endl;

            while(templateFile) {

                string line = "";
                getline(templateFile, line);
                Helper::replaceClassName(line, fileName);

                if (line == "") {
                    file << endl;
                } else {
                    file << line << endl;
                }

                if(!templateFile) {
                    break;
                }
            }
        } catch(const ifstream::failure& e) {
            cout << "There was a problem with the extension provider:" << e.what() << endl;
        }

        templateFile.close();
    }
    file.close();
}

void ICommandBehavior::WriteCodeNow() {
    CreateProlog();
    bool fileAllowsComments = comment != "{}";
    if (fileAllowsComments) {
        CreateCommentHeader();
    }
    CreateMainTemplate();
}

void ICommandBehavior::WriteFile(bool unknownFile)
{
    RegisterDateOfCreation();
    loadArgsToCNHEngine();
    auto templates = engine.FindTemplates(fileName);
    if (unknownFile){
        templates = engine.FindTemplates("filename.unknown_ext_type");
    }
    auto result = engine.RenderFile(std::get<0>(templates[0]).string());
    fstream file = startUsingFile();
    for (auto& line: result) {
        file << line << endl;
    }
    file.close();
}

void ICommandBehavior::loadArgsToCNHEngine()
{
    RegisterDateOfCreation();
    //engine.LoadDataFile("data.json");  // TODO check if we can add config in json to play with the engine
    engine.LoadDataValue("cnh_date", dateOfCreation);
    engine.LoadDataValue("cnh_file", fileName);
    engine.LoadDataValue("cnh_name", author);
    engine.LoadDataValue("cnh_description", description);
    if (hasCopyRight) {
        string current_year = to_string(year);
        string copyright = "Copyright (C) " + current_year + " " + author + ". All rights reserved.";
        engine.LoadDataValue("cnh_has_copyright", copyright);
    }
    if (!comment.empty()) {
        engine.LoadDataValue("cnh_comment", comment);
        if (!commentClosureOpt.empty()) {
            engine.LoadDataValue("cnh_comment_closure", commentClosureOpt);
        }
    }
}

void ICommandBehavior::RegisterDateOfCreation() {
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt) - 1] = '\0';
    dateOfCreation = string(dt);

    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
}


string ICommandBehavior::getLang(string fileName) {
    // Getting the extension of the file
	string ext = "." + Helper::getExtension(fileName);
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
        cout << "There was a problem with the extension provider:" << e.what() << endl;
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
        cout << "There was a problem with the extension provider:" << e.what() << endl;
    }

    file.close();
}


void ICommandBehavior::feed(cnh::arguments args) {
    fileName = args.fileName;
    char const* user = getenv("USER");
    char const* username = getenv("USERNAME");
    string myUser = user != NULL ? string(user) : username != NULL ? string(username) : string();
    myUser = myUser != "" ? myUser : "Unknown User";
    author = args.author != "" ? args.author : myUser;
    description = args.description;
    hasCopyRight = args.copyRight;
    fileNames = args.fileNames;
    bunchExt = args.bunchExt;
    numOfFiles = args.numFiles;
}

std::string ICommandBehavior::nTimesThisString (std::string text, int times) {
    std::string tmp;
    for (int i = 0; i < times; i++) {
        tmp += text;
    }
    return tmp;
}

std::string ICommandBehavior::includeHeaderAttribute(std::string title, std::string text, int size)
{
    // word variable to store word
    std::string word;

    // making a string stream
    std::stringstream iss(text);

    std::string chain = " " + title + " ";
    std::string space = " ";
    size_t tmpSize = title.size() + 2;
    //int tmpSize = chain.size();
    size_t newLineTmpSize = size + (comment.size());

    // Read and process each word.
    while (iss >> word) {
        tmpSize += (getStringLength(word) + 1);
        if (tmpSize <= size) {
            chain += word + space;
        } else {
            size_t lineLength = tmpSize - getStringLength(word) - 1;
            size_t numSpaces = size - lineLength;

            chain += nTimesThisString(space, (int)numSpaces);
            chain += "  " + commentClosureOpt + "\n";
            std::string newLine = comment + nTimesThisString(space, (int)title.size()+1) + word + " ";
            tmpSize = newLine.size();
            chain += newLine;
            size = (int)newLineTmpSize;
        }
    }
    chain += nTimesThisString(space, size - (int)tmpSize + 1);
    return chain;
}

bool ICommandBehavior::isSpecialChar(char letter) {
    bool flag = (letter >= 27 && letter <= 127);
    return !flag;
}

int ICommandBehavior::getStringLength(std::string word) {
    int specialChars = 0;
    size_t wordLength = word.length();
    for (int i = 0; i < wordLength; i++) {
        if (isSpecialChar(word[i])) {
            specialChars++;
        }
    }
    return (int)wordLength - (specialChars / 2);
}
