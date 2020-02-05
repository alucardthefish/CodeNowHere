#ifndef ONLYFILEBEHAVIOR_H
#define ONLYFILEBEHAVIOR_H

// **************************************************************************** 
// File: OnlyFileBehavior.h 
// Author: Sergio Ortiz Paz 
// Created: Mon Feb  3 19:41:39 2020 
// Description: Behavior for the first command option 
// **************************************************************************** 

#include <string>

#include "ICommandBehavior.h"

class OnlyFileBehavior : public ICommandBehavior
{
    public:
    std::string dataPath;
    OnlyFileBehavior();
    void CreateCode();
};

#endif