// ****************************************************************************
// File: BunchFileBehavior.cpp
// Author: Sergio Ortiz Paz
// Created: Sun Feb 23 18:49:37 2020
// Description: Implement the abstract class for third command option
// ****************************************************************************

#include "../headers/BunchFileBehavior.h"
#include <csignal>
#include <iostream>

using namespace std;

// Signal handler function
void signalHandlerBunch(int signum) {
    cout << "The program was not able to find a template for this file type" << endl;
    exit(signum);
}

BunchFileBehavior::BunchFileBehavior() {
    // Set up signal handler for segmentation faults
    signal(SIGSEGV, signalHandlerBunch);
}

void  BunchFileBehavior::CreateCode() {

    string ext = bunchExt;
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

    if (!ValidateExt(ext))
    {
        cout << "The extension option --ext must start with a dot. For instance: '.py'" << endl;
        return;
    }

    bool uknownFileWantsCommentHeader = false;
    bool isUnknownFile = false;
    if (!engine.IsFileExtensionTypeSupported(ext)) {
        isUnknownFile = true;
        uknownFileWantsCommentHeader = Helper::RequireHeaderAssistance(fileName, comment, commentClosureOpt);
    }

    for (int i = 0; i < numOfFiles; i++)
    {
        string mFileName = "File";
        mFileName += to_string(i+1);
        mFileName += ext;

        fileName = mFileName;

        if (!Helper::fileExist(fileName)) { // File is created only if it doesn't already exist

            try
            {
                WriteFile(isUnknownFile);
                cout << fileName << " created!" << endl;
            }
            catch(const std::exception& e)
            {
                cout << "An error occurred: " << e.what() << endl;
            }
        } // ends fileExists
    } // ends for

}


bool BunchFileBehavior::ValidateExt(string ext) {
    bool result = false;
	try {
		regex re("^\\.([A-Za-z0-9_-]*)$");
		smatch match;
		result = regex_search(ext, match, re) && (match.size() > 1);
	} catch (regex_error& e) {
		cout << "Error:" << e.what() << endl;
	}
	return result;
}
