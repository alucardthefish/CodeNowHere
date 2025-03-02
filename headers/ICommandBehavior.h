// ****************************************************************************
// File: ICommandBehavior.h
// Author: Sergio Ortiz Paz
// Created: Mon Feb  3 18:20:46 2020
// Description: Abstract class for command behavior
// ****************************************************************************
#ifndef ICOMMANDBEHAVIOR_H
#define ICOMMANDBEHAVIOR_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "cnh_structs.h"
#include <cstdlib>
#include <vector>

#include "Helper.h"
#include "cnhengine.h"

class ICommandBehavior
{
    public:
    std::string fileName;
    std::string comment;
    std::string commentClosureOpt;
    std::string author;
    std::string dateOfCreation;
    std::string description;
    std::string dataPath;
    int year;
    bool hasCopyRight;
    std::vector<std::string> fileNames;
    std::string bunchExt;
    int numOfFiles;
    CnhEngine engine;

    fstream startUsingFile();
    void CreateProlog();
    void CreateCommentHeader(int);
    void CreateMainTemplate();
    void WriteCodeNow();
    void WriteFile(); // new method for new approach
    void loadArgsToCNHEngine(); // new method for new approach
    void RegisterDateOfCreation();

    std::string getLang(std::string fileName);
    void blowCommentByExtensions(std::string ext);
    void feed(cnh::arguments args);
    std::string nTimesThisString (std::string text, int times);
    std::string includeHeaderAttribute(std::string title, std::string text, int size);
    bool isSpecialChar(char);
    int getStringLength(std::string);
    virtual void CreateCode() = 0;
    virtual ~ICommandBehavior() {};
};


#endif