// ****************************************************************************
// File: Helper.cpp
// Author: Sergio Ortiz Paz
// Created: Tue Feb  4 01:00:22 2020
// Description: Implement util methods
// ****************************************************************************

#include "../headers/Helper.h"
#include <cstring>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// Helper method to find resources in multiple candidate paths
string Helper::findResourcePath(const vector<string>& candidatePaths) {
    for (const auto& path : candidatePaths) {
        try {
            if (!path.empty() && fs::exists(path) && fs::is_directory(path)) {
                return path;
            }
        } catch (const fs::filesystem_error&) {
            // Path doesn't exist or can't be accessed, continue to next candidate
            continue;
        }
    }
    
    // If no path found, return the first candidate as fallback
    // (typically the local development path or relative path)
    return candidatePaths.empty() ? "" : candidatePaths[0];
}

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
        cout << "ERROR: syntax error in the regular expresion:" << e.what() << endl;
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
        cout << "PROBLEM" << e.what() << endl;
    }
    return state;
}

bool Helper::questionReceptor(string answer, string dflt) {
    bool state = false;

    if (answer.empty())
        answer = dflt;
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if (answer == "y" || answer == "yes") {
        state = true;
    }
    return state;
}


string Helper::getExtension(const string& fileName) {
    size_t dotPosition = fileName.rfind('.');
    if (dotPosition == string::npos) {
        return "";
    }
    string ext = fileName.substr(dotPosition + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
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
	size_t si_ze = CLASSNAMETMPL.length();
	string nameFile = getNameOfFile(fileName);
	size_t poss = className.find(CLASSNAMETMPL);
	if (poss != string::npos) {
		className.replace(poss, si_ze, nameFile);
	}
}

string Helper::getDataPath() {
    // Priority 1: Check environment variable
    char *envPath = getenv("CNH_EXTDATA");
    if (envPath != NULL) {
        size_t len = strlen(envPath);
        if (len > 0) {
            string result(envPath);
            if (result[result.length() - 1] != '/' && result[result.length() - 1] != '\\') {
                result += "/";
            }
            return result;
        }
    }

    // Priority 2: Check multiple standard locations
    vector<string> candidatePaths = {
        // Local development paths (relative to build directory)
        LibConstants::LOCAL_DATA,
        // Standard Linux/Unix paths
        "/usr/share/cnh/cnh/",
        "/usr/local/share/cnh/cnh/",
        // macOS paths
        "/usr/local/share/cnh/cnh/",
        // Windows paths (relative to installation)
        "./share/cnh/cnh/",
        "../share/cnh/cnh/",
    };
    
    string foundPath = findResourcePath(candidatePaths);
    if (foundPath[foundPath.length() - 1] != '/' && foundPath[foundPath.length() - 1] != '\\') {
        foundPath += "/";
    }
    return foundPath;
}

string Helper::getTemplatePath() {
    // Priority 1: Check environment variable
    char *envPath = getenv("CNH_TEMPLATES");
    if (envPath != NULL) {
        size_t len = strlen(envPath);
        if (len > 0) {
            string result(envPath);
            if (result[result.length() - 1] != '/' && result[result.length() - 1] != '\\') {
                result += "/";
            }
            return result;
        }
    }

    // Priority 2: Check multiple standard locations
    vector<string> candidatePaths = {
        // Local development paths (relative to build directory)
        LibConstants::LOCAL_TEMPLATES,
        // Standard Linux/Unix paths
        "/usr/share/cnh/cnh_templates/",
        "/usr/local/share/cnh/cnh_templates/",
        // macOS paths
        "/usr/local/share/cnh/cnh_templates/",
        // Windows paths (relative to installation)
        "./share/cnh/cnh_templates/",
        "../share/cnh/cnh_templates/",
    };
    
    string foundPath = findResourcePath(candidatePaths);
    if (foundPath[foundPath.length() - 1] != '/' && foundPath[foundPath.length() - 1] != '\\') {
        foundPath += "/";
    }
    return foundPath;
}

bool Helper::RequireHeaderAssistance(const string& fileName, string &initCommentChar, string &finalCommentChar) {
    bool decisionFlag;

    cout << "The program does not recognize the extension associated to the file: '" << fileName;
    cout << "'. Do you want to add a header comment to this unknown file (Y/n): ";
    string decision;
    getline(cin, decision);
    decisionFlag = questionReceptor(decision, "y");
    if (decisionFlag) {
        cout << "Enter the in-line comment syntax for this type of programming language: ";
        while (true) {
            string value;
            getline(cin, value);
            if (!value.empty()) {
                initCommentChar = value;
                break;
            }
            cout << "Input cannot be empty. Try again: ";
        }

        cout << endl << "Has the inline comment character entered previously a closing character? (Y/n): ";
        getline(cin, decision);
        if (questionReceptor(decision, "Y")) {
            cout << "Enter the closing comment character: ";
            while (true) {
                string value_2;
                getline(cin, value_2);
                if (!value_2.empty()) {
                    finalCommentChar = value_2;
                    break;
                }
                cout << "Input cannot be empty. Try again: ";
            }
        }
    }
    return decisionFlag;
}

