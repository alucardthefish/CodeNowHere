// **************************************************************************** 
// File: ManyFileBehavior.h 
// Author: Sergio Ortiz Paz 
// Created: Thu Feb 13 18:06:38 2020 
// Description: Behavior for the second command options 
// **************************************************************************** 
#ifndef MANYFILEBEHAVIOR_H
#define MANYFILEBEHAVIOR_H

#include "ICommandBehavior.h"

class ManyFileBehavior : public ICommandBehavior
{
	public:
		ManyFileBehavior();
		void CreateCode();
};

#endif

