// ****************************************************************************
// File: Helper.h
// Author: Sergio Ortiz Paz
// Created: Tue Feb  4 00:59:06 2020
// Description: Static class holding util methods
// ****************************************************************************
#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

#ifndef MYLIB_CONSTANTS_H
#define MYLIB_CONSTANTS_H

namespace LibConstants
{
    const string LOCAL_DATA = "../extdata/";
    const string LOCAL_TEMPLATES = "../templates/";
}
#endif

class Helper {
    private:
    string dataPath;
    string templatePath;
    Helper();   //Disallow creating an instance

    public:
    static bool validateFileName(const string& fileName);
    static bool fileExist(const string& fileName);
    static bool questionReceptor(string answer, string dflt = "");
    static string getDataPath();
    static string getTemplatePath();

    static string getExtension(const string& fileName);
    static string getNameOfFile(const string& fileName);
    static void replaceClassName(string& className, const string& fileName);
    static bool RequireHeaderAssistance(const string& fileName, string &initCommentChar, string &finalCommentChar);
};

#endif