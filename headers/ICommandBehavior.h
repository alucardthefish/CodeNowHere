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
#include <map>
#include <bits/stdc++.h>
#include "docopt.h"

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

    void CreateCommentHeader();
    void CreateMainTemplate(std::ofstream& codeFile, std::string fileName);
    std::string getLang(std::string fileName);
    void blowCommentByExtensions(std::string ext);
    void feed(std::map<std::string, docopt::value> args);
    virtual void CreateCode() = 0;
};


#endif