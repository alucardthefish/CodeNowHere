#ifndef CODENOWHERE_H
#define CODENOWHERE_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <bits/stdc++.h>
#include "docopt.h"
#include "../headers/ICommandBehavior.h"

using namespace std;

class CodeNowHere {
    private:
    string fileName;
    string author;
    string dateOfCreation;
    string description;
    string comment;
    string commentClosureOpt;
    map<string, docopt::value> arguments;
    ICommandBehavior *iCB; //Abstract class


    public:
    CodeNowHere();
    CodeNowHere(map<string, docopt::value> input);
    void initArgsValues(map<string, docopt::value> input);
    void controller();

};
#endif
