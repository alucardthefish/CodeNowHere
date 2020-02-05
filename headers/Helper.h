#ifndef HELPER_H
#define HELPER_H
// **************************************************************************** 
// File: Helper.h 
// Author:  
// Created: Tue Feb  4 00:59:06 2020 
// Description:  
// **************************************************************************** 

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <bits/stdc++.h>

using namespace std;

#ifndef MYLIB_CONSTANTS_H
#define MYLIB_CONSTANTS_H

namespace LibConstants
{
    const string LOCAL_DATA = "../extdata/";
}
#endif

class Helper {
    private:
    string dataPath;
    Helper();   //Disallow creating an instance

    public:
    static bool validateFileName(string fileName);
    static bool fileExist(string fileName);
    static bool questionReceptor(string answer);
    static string getDataPath();

    static string getExtension(string fileName);
    static string getNameOfFile(string fileName);
    static void replaceClassName(string& className, string fileName);
    static bool RequireHeaderAssistance(string fileName, string &initCommentChar, string &finalCommentChar);
};

#endif