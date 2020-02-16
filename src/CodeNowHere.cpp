//******************************************************************************************
// File: CodeNowHere.cpp
// Author: Sergio Ortiz Paz
// Created: Mon Dec 23 22:18:25 2019
// Description: Implementation for controlling the console options behaviors
//******************************************************************************************

#include "../headers/CodeNowHere.h"

CodeNowHere::CodeNowHere(map<string, docopt::value> input) {
    arguments = input;
    Controller();
}

void CodeNowHere::Controller() {
    //ICommandBehavior *iCB;
    if (arguments["this"].asBool()){
        iCB = new OnlyFileBehavior();
    } else if (arguments["these"].asBool()) {
        iCB = new ManyFileBehavior();
    }
}

void CodeNowHere::Execute() {
    iCB->feed(arguments);
    iCB->CreateCode();
}
