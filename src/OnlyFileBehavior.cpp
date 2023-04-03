// **************************************************************************** 
// File: OnlyFileBehavior.cpp 
// Author: Sergio Ortiz Paz 
// Created: Mon Feb  3 19:47:40 2020 
// Description: Implement the abstract class for first commd option 
// **************************************************************************** 

#include <cstdio>
#include "../headers/OnlyFileBehavior.h"

using namespace std;

OnlyFileBehavior::OnlyFileBehavior() {
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
        string ext = Helper::getExtension(fileName);
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
        
        blowCommentByExtensions(ext);

        if (comment.empty()) {  // Check if type file is not supported in the program
            if (!Helper::RequireHeaderAssistance(fileName, comment, commentClosureOpt)) {
                ofstream file;
                file.open(fileName);
                file.close();
            } else {
                WriteCodeNow();
            }
        } else {
            WriteCodeNow();
        }
        cout << fileName << " created!" << endl;
    } else {
        cout << fileName << " is not a valid file name. File name must be in this form 'filename.ext'" << endl;
    }

}

