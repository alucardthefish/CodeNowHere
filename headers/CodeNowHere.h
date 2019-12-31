#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <ctime>
#include <algorithm>
#include <cctype>

using namespace std;

class CodeNowHere {
    private:
    map<string, string> commentMap;
    string fileName;
    string author;
    string dateOfCreation;
    string description;
    string comment;

    public:
    CodeNowHere();
    void blowExtensions();
    void captureConsoleInput(int argc, char * argv[]);
    string getExtension(string fileName);
    void addCommentHeader();
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

