// **************************************************************************** 
// File: ManyFileBehavior.cpp 
// Author: Sergio Ortiz Paz 
// Created: Thu Feb 13 18:10:45 2020 
// Description: Implement the abstract class for second command option 
// **************************************************************************** 


#include "../headers/ManyFileBehavior.h"

using namespace std;

ManyFileBehavior::ManyFileBehavior() {
}

void ManyFileBehavior::CreateCode() {
    
    cout << "Creating files..." << endl;
    int numFiles = fileNames.size();
    int numFilesCreated = 0;
    for(auto const& mFileName : fileNames) {
        
        fileName = mFileName;

        if (Helper::validateFileName(fileName)) {
            // Decision in case file already exist
            if (Helper::fileExist(fileName)){
                cout << "File " << fileName << " already exists in this directory. If you continue its content will be replaced" << endl;
                string chose;
                cout << "Do you want to continue (Y/n): ";
                cin >> chose;
                if (!Helper::questionReceptor(chose)) {
                    continue;
                }
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
            numFilesCreated++;
        } else {
            cout << fileName << " is not a valid file name. File name must be in this form 'filename.ext'" << endl;
        }
    }//end for
    cout << "Output: " << numFilesCreated << "/" << numFiles << " files were created" << endl;
}


