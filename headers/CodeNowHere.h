// **************************************************************************** 
// File: CodeNowHere.h 
// Author: Sergio Ortiz Paz 
// Created: Mon Dec 23 22:12:55 2019 
// Description: Class in charge of control console flow
// ****************************************************************************
#ifndef CODENOWHERE_H
#define CODENOWHERE_H

#include <map>
#include "docopt.h"

#include "ICommandBehavior.h"
#include "OnlyFileBehavior.h"
#include "ManyFileBehavior.h"

using namespace std;

class CodeNowHere {
    private:
    map<string, docopt::value> arguments;
    ICommandBehavior *iCB; //Abstract class


    public:
    CodeNowHere(map<string, docopt::value> input);
    void Controller();
    void Execute();

};
#endif
