//******************************************************************************************
// File: CodeNowHere.cpp
// Author: Sergio Ortiz Paz
// Created: Mon Dec 23 22:18:25 2019
// Description: Implementation for controlling the console options behaviors
//******************************************************************************************

#include "../headers/CodeNowHere.h"

CodeNowHere::CodeNowHere(cnh::arguments argStruct) {
    data = argStruct;
    Controller();
}

void CodeNowHere::Controller() {
    //ICommandBehavior *iCB;
    if (data.optThis) {
        iCB = new OnlyFileBehavior();
    } else if (data.optThese) {
        iCB = new ManyFileBehavior();
    } else if (data.optBunch) {
        iCB = new BunchFileBehavior();
    }
}

void CodeNowHere::Execute() {
    iCB->feed(data);
    iCB->CreateCode();
}
