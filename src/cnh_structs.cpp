// **************************************************************************** 
// File: cnh_structs.cpp 
// Author: Sergio Ortiz Paz 
// Created: Wed Mar 18 15:00:14 2020 
// Description: Implement arguments structure 
// **************************************************************************** 


#include "../headers/cnh_structs.h"

namespace cnh {

    arguments::arguments() {
        fileName = "";
        author = "";
        description = "";
        copyRight = false;
        fileNames = std::vector<std::string>();
        bunchExt = "";
        numFiles = 0;
        optThis = false;
        optThese = false;
        optBunch = false;
    }

    arguments initForOptionThis(std::string fileName, std::string author, std::string desc, bool copyRight) {
        std::vector<std::string> emptyVector;
        arguments ar;
        ar.fileName = fileName;
        ar.author = author;
        ar.description = desc;
        ar.copyRight = copyRight;
        ar.optThis = true;
        return ar;
    }

    arguments initForOptionThese(std::vector<std::string> fileNames, std::string author, bool copyRight) {
        arguments ar;
        ar.author = author;
        ar.fileNames = fileNames;
        ar.copyRight = copyRight;
        ar.optThese = true;
        return ar;
    }

    arguments initForOptionBunch(int numFiles, std::string bunchExt, std::string author, bool copyRight)  {
        std::vector<std::string> emptyVector;
        arguments ar;
        ar.author = author;
        ar.copyRight = copyRight;
        ar.numFiles = numFiles;
        ar.bunchExt = bunchExt;
        ar.optBunch = true;
        return ar;
    }

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
        bool optBunch)  {
            
            arguments ar;
            ar.fileName = fileName;
            ar.author = author;
            ar.description = desc;
            ar.copyRight = copyRight;
            ar.fileNames = fileNames;
            ar.bunchExt = bunchExt;
            ar.numFiles = numFiles;
            ar.optThis = optThis;
            ar.optThese = optThese;
            ar.optBunch = optBunch;
            return ar;
        }
}

