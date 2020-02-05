//******************************************************************************************
// File: CodeNowHere.cpp
// Author: Sergio Ortiz Paz
// Created: Mon Dec 23 22:18:25 2019
// Description: Classes in charge of process the input data from console and showing output
//******************************************************************************************

#include "../headers/CodeNowHere.h"
//#include "../headers/ICommandBehavior.h"
#include "../headers/OnlyFileBehavior.h"

CodeNowHere::CodeNowHere() {
    
}

CodeNowHere::CodeNowHere(map<string, docopt::value> input) {
    arguments = input;
}

void CodeNowHere::initArgsValues(map<string, docopt::value> input) {
    comment = "";
    commentClosureOpt = "";
    fileName = input["<filename>"].asString();
    author = (!input["--author"].asStringList().empty()) ? input["--author"].asStringList().at(0) : "";
    description = (!input["--desc"].asStringList().empty()) ? input["--desc"].asStringList().at(0) : "";
}

void CodeNowHere::controller() {
    //ICommandBehavior *iCB;
    if (!arguments["<filename>"].asString().empty()) {
        iCB = new OnlyFileBehavior();
    } else {
        cout << "hacer otra cosa entonces" << endl;
    }
    iCB->feed(arguments);
    iCB->CreateCode();
}
