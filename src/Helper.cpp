// **************************************************************************** 
// File: Helper.cpp 
// Author: Sergio Ortiz Paz 
// Created: Tue Feb  4 01:00:22 2020 
// Description: Implement util methods 
// **************************************************************************** 

#include "../headers/Helper.h"

using namespace std;

bool Helper::validateFileName(const string& fileName)
// validateFileName: receives the file name string and evaluates if its a correct format
// returns: true if is correct false otherwise.
{
    bool result = false;
    try {
        regex re("^[A-Za-z0-9_-]*(\\.)?[A-Za-z0-9]*(\\.)[A-Za-z0-9]+$");
        smatch match;
        result = regex_search(fileName, match, re) && (match.size() > 1);
    } catch (regex_error& e) {
        cout << "ERROR: syntax error in the regular expresion" << endl;
    }
    return result;
}

bool Helper::fileExist(const string& fileName) {
    ifstream file;
    bool state = false;
    try {
        file.open(fileName);
        if (file.is_open()) {
            state = true;
            file.close();
        }
    } catch(const ifstream::failure& e) {
        cout << "PROBLEM" << endl;
    }
    return state;
}

bool Helper::questionReceptor(string answer) {
    bool state = false;
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if (answer == "y" || answer == "yes") {
        state = true;
    }
    return state;
}


string Helper::getExtension(const string& fileName) {
    string ext;
    size_t dotPosition = fileName.rfind('.');
    ext = fileName.substr(dotPosition);
    return ext;
}

string Helper::getNameOfFile(const string& fileName) {
    string name;
	size_t dotPosition = fileName.rfind('.');
	name = fileName.substr(0, dotPosition);
    return name;
}



void Helper::replaceClassName(string& className, const string& fileName) {
	const string CLASSNAMETMPL = "HelloWorld";
	int si_ze = CLASSNAMETMPL.length();
	string nameFile = getNameOfFile(fileName);
	size_t poss = className.find(CLASSNAMETMPL);
	if (poss != string::npos) {
		className.replace(poss, si_ze, nameFile);
	}
}

string Helper::getDataPath() {
    char *envPath = getenv("CNH_EXTDATA");
    if (envPath != NULL) {
        size_t len = strlen(envPath);
        if (len > 0) {
            if (envPath[len - 1] != '/' && envPath[len - 1] != '\\') {
                return string(envPath) + "/";
            }
            else {
                return envPath;
            }
        }
    }

    string dataPath = LibConstants::LOCAL_DATA;
    #ifdef DATA_LOCATION
        dataPath = DATA_LOCATION;
        dataPath += "/";
    #endif
    return dataPath;
}

bool Helper::RequireHeaderAssistance(const string& fileName, string &initCommentChar, string &finalCommentChar){
    bool decisionFlag;

    cout << "The program does not recognize the extension associated to the file: '" << fileName;
    cout << "'. Do you want to add a header comment to this unknown file (y/n): ";
    string decision;
    cin >> decision;
    decisionFlag = questionReceptor(decision);
    if (decisionFlag) {
        cout << "Enter the in-line comment syntax for this type of programming language: ";
        cin.clear();
        cin.ignore(10000, '\n');
        getline(cin, initCommentChar);
        while(initCommentChar.empty()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "try again: ";
            getline(cin, initCommentChar);
        }
        cout << endl << "Has the inline comment character entered previously a closing character? (Y/n): ";
        cin >> decision;
        if (questionReceptor(decision)) {
            cout << "Enter the closing comment character: ";
            cin.clear();
            cin.ignore(10000, '\n');
            getline(cin, finalCommentChar);
            while(finalCommentChar.empty()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "try again: ";
                getline(cin, finalCommentChar);
            }
        }
    }
    return decisionFlag;
}

