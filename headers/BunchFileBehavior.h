// **************************************************************************** 
// File: BunchFileBehavior.h 
// Author: Sergio Ortiz Paz 
// Created: Sun Feb 23 18:42:54 2020 
// Description: Behavior for creating a number of file 
// **************************************************************************** 
#ifndef BUNCHFILEBEHAVIOR_H
#define BUNCHFILEBEHAVIOR_H

#include "ICommandBehavior.h"

class BunchFileBehavior : public ICommandBehavior
{
    public:
        BunchFileBehavior();
        void CreateCode();
        bool ValidateExt(string ext);
};

#endif
