// ****************************************************************************
// File: ManyFileBehavior.cpp
// Author: Sergio Ortiz Paz
// Created: Thu Feb 13 18:10:45 2020
// Description: Implement the abstract class for second command option
// ****************************************************************************

#include <cstdio>
#include <csignal>
#include "../headers/ManyFileBehavior.h"

using namespace std;

// Signal handler function
void signalHandlerMany(int signum) {
    cout << "The program was not able to find a template for this file type" << endl;
    exit(signum);
}

ManyFileBehavior::ManyFileBehavior() {
    // Set up signal handler for segmentation faults
    signal(SIGSEGV, signalHandlerMany);
}

void ManyFileBehavior::CreateCode() {

    cout << "Creating files..." << endl;
    size_t numFiles = fileNames.size();
    int numFilesCreated = 0;
    for(auto const& mFileName : fileNames) {

        fileName = mFileName;

        if (Helper::validateFileName(fileName)) {
            // Decision in case file already exist
            if (Helper::fileExist(fileName)){
                cout << "File " << fileName << " already exists in this directory. If you continue its content will be replaced" << endl;
                string chose;
                cout << "Do you want to continue (Y/n): ";
                getline(cin, chose);
                if (!Helper::questionReceptor(chose, "y")) {
                    continue;
                }
                remove(fileName.c_str());
            }

            bool uknownFileWantsCommentHeader = false;
            bool isUnknownFile = false;
            if (!engine.IsFileExtensionTypeSupported(fileName)) {
                isUnknownFile = true;
                comment = "";
                commentClosureOpt = "";
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

            numFilesCreated++;
        } else {
            cout << fileName << " is not a valid file name. File name must be in this form 'filename.ext'" << endl;
        }
    }//end for
    cout << "Output: " << numFilesCreated << "/" << numFiles << " files were created" << endl;
}


