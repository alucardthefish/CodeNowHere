// **************************************************************************** 
// File: CodeNowHere.h 
// Author: Sergio Ortiz Paz 
// Created: Mon Dec 23 22:12:55 2019 
// Description: Class in charge of control console flow
// ****************************************************************************
#ifndef CODENOWHERE_H
#define CODENOWHERE_H

#include "ICommandBehavior.h"
#include "OnlyFileBehavior.h"
#include "ManyFileBehavior.h"
#include "BunchFileBehavior.h"

#include "../headers/cnh_structs.h"

using namespace std;

class CodeNowHere {
    private:
    cnh::arguments data;
    ICommandBehavior *iCB; //Abstract class

    public:
    CodeNowHere(cnh::arguments argStruct);
    void Controller();
    void Execute();

};
#endif
