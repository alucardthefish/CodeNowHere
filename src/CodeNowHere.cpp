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

CodeNowHere::~CodeNowHere() {
    // std::unique_ptr automatically deletes iCB when out of scope
}

void CodeNowHere::Controller() {
    if (data.optThis) {
        iCB = std::make_unique<OnlyFileBehavior>();
    } else if (data.optThese) {
        iCB = std::make_unique<ManyFileBehavior>();
    } else if (data.optBunch) {
        iCB = std::make_unique<BunchFileBehavior>();
    }
}

void CodeNowHere::Execute() {
    iCB->feed(data);
    iCB->CreateCode();
}
