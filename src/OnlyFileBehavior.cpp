// ****************************************************************************
// File: OnlyFileBehavior.cpp
// Author: Sergio Ortiz Paz
// Created: Mon Feb  3 19:47:40 2020
// Description: Implement the abstract class for first commd option
// ****************************************************************************

#include <cstdio>
#include <csignal>
#include "../headers/OnlyFileBehavior.h"

using namespace std;

// Signal handler function
void signalHandler(int signum) {
    cout << "The program was not able to find a template for this file type" << endl;
    exit(signum);
}

OnlyFileBehavior::OnlyFileBehavior() {
    // Set up signal handler for segmentation faults
    signal(SIGSEGV, signalHandler);
}

void OnlyFileBehavior::CreateCode() {
    // file name validation
    if (Helper::validateFileName(fileName)) {
        // Decision in case file already exist
        if (Helper::fileExist(fileName)){
            cout << "File " << fileName << " already exists in this directory. If you continue its content will be replaced" << endl;
            string chose;
            cout << "Do you want to continue (Y/n): ";
            getline(cin, chose);
            if (!Helper::questionReceptor(chose, "y")) {
                return;
            }
            remove(fileName.c_str());
        }

        bool uknownFileWantsCommentHeader = false;
        bool isUnknownFile = false;
        if (!engine.IsFileExtensionTypeSupported(fileName)) {
            isUnknownFile = true;
            Helper::RequireHeaderAssistance(fileName, comment, commentClosureOpt);
        }

        try
        {
            WriteFile(isUnknownFile);
            cout << fileName << " created!" << endl;
        }
        catch(const std::exception& e)
        {
            cout << "An error occurred: " << e.what() << endl;
        }

    } else {
        cout << fileName << " is not a valid file name. File name must be in this form 'filename.ext'" << endl;
    }

}

