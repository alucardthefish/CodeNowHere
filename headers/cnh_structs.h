// **************************************************************************** 
// File: cnh_structs.h 
// Author: Sergio Ortiz Paz 
// Created: Wed Mar 18 00:19:58 2020 
// Description: Data structure to store args data 
// **************************************************************************** 

#ifndef CNH_STRUCTS_H
#define CNH_STRUCTS_H

#include <string>
#include <vector>

namespace cnh {

    struct arguments {
        
        std::string fileName;
        std::string author;
        std::string description;
        bool copyRight;
        std::vector<std::string> fileNames;
        std::string bunchExt;
        int numFiles;
        bool optThis;
        bool optThese;
        bool optBunch;

        arguments();
        
    };

    arguments initForOptionThis(std::string fileName, std::string author, std::string desc, bool copyRight);

    arguments initForOptionThese(std::vector<std::string> fileNames, std::string author, bool copyRight);

    arguments initForOptionBunch(int numFiles, std::string bunchExt, std::string author, bool copyRight);

    arguments init(
        std::string fileName, 
        std::string author, 
        std::string desc, 
        bool copyRight,
        std::vector<std::string> fileNames,
        std::string bunchExt, 
        int numFiles, 
        bool optThis, 
        bool optThese,
        bool optBunch);

} // cnh namespace

#endif