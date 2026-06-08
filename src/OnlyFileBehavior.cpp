// ****************************************************************************
// File: OnlyFileBehavior.cpp
// Author: Sergio Ortiz Paz
// Created: Mon Feb  3 19:47:40 2020
// Description: Implement the abstract class for first commd option
// ****************************************************************************

#include <cstdio>
#include <csignal>
#include <cstdlib>
#include "../headers/OnlyFileBehavior.h"

using namespace std;

// Signal handler function - async-signal-safe
void signalHandler(int signum) {
    // Only async-signal-safe functions allowed here
    // std::cout and exit() are NOT async-signal-safe
    std::_Exit(1);
}

OnlyFileBehavior::OnlyFileBehavior() {
    // Set up signal handler for segmentation faults
    // Note: This is still not ideal (constructors shouldn't set signal handlers)
    // Consider moving to main() for better thread-safety
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

