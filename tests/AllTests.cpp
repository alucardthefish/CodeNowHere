// **************************************************************************** 
// File: AllTests.cpp 
// Author: alucardthefish 
// Created: Mon Mar 16 21:18:51 2020 
// Description: Main Program for running unit tests 
// **************************************************************************** 


#include <iostream>

#include "gtest/gtest.h"

// Tests
#include "ICommandBehaviorTest.h"


int main(int argc, char * argv[]) {
    std::cout << "Test Runner (Start)" << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

