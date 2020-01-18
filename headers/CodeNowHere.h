#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <bits/stdc++.h>

using namespace std;

#ifndef MYLIB_CONSTANTS_H
#define MYLIB_CONSTANTS_H

namespace LibConstants
{
    const string LOCAL_DATA = "../extdata/";
}
#endif

class CodeNowHere {
    private:
    map<string, string> commentMap;
    string fileName;
    string author;
    string dateOfCreation;
    string description;
    string comment;
    string dataPath;

    public:
    CodeNowHere();
    void blowExtensions();
    void captureConsoleInput(int argc, char * argv[]);
    string getExtension(string fileName);
    string getNameOfFile(string fileName);
    void addCommentHeader();
    string getLang(string fileName);
    void replaceClassName(string& className, string filename);
    void addMainTmplate(ofstream& codeFile, string fileName);
    void createCode();

};

class Helper {
    private:
    string version;
    map<string, string> messages;

    public:
    Helper();
    void blowMessages();
    string getBadInput();
    string getUsage();
    string getVersion();
    bool validateFileName(string fileName);
};

