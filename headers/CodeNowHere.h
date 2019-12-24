#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <ctime>

using namespace std;

class CodeNowHere {
    private:
    map<string, string> commentMap;
    string fileName;
    string author;
    string dateOfCreation;
    string description;

    public:
    CodeNowHere();
    void blowExtensions();
    void captureConsoleInput(int argc, char * argv[]);
    string getExtension(string fileName);
    void createCode();

};

