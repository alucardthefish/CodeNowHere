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
#include <bits/stdc++.h>
#include "cnh_structs.h"
#include <cstdlib>
#include <vector>

#include "Helper.h"

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

    fstream startUsingFile();
    void CreateProlog();
    void CreateCommentHeader();
    void CreateMainTemplate();
    void WriteCodeNow();
    void RegisterDateOfCreation();

    std::string getLang(std::string fileName);
    void blowCommentByExtensions(std::string ext);
    void feed(cnh::arguments args);
    virtual void CreateCode() = 0;
};


#endif