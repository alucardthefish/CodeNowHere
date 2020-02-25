// **************************************************************************** 
// File: BunchFileBehavior.cpp 
// Author: Sergio Ortiz Paz 
// Created: Sun Feb 23 18:49:37 2020 
// Description:  
// **************************************************************************** 

#include "../headers/BunchFileBehavior.h"
#include <iostream>

using namespace std;

BunchFileBehavior::BunchFileBehavior() {

}

void  BunchFileBehavior::CreateCode() {

    string ext = bunchExt;
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

    if (!ValidateExt(ext))
    {
        cout << "The extension option --ext must start with a dot. For instance: '.py'" << endl;
        return;
    }

    blowCommentByExtensions(ext);
    bool uknownFileWantsCommentHeader = false;
    bool isUnknownFile = comment.empty();

    if (isUnknownFile) {
        uknownFileWantsCommentHeader= Helper::RequireHeaderAssistance(fileName, comment, commentClosureOpt);
    }
    

    for (int i = 0; i < numOfFiles; i++)
    {
        string mFileName = "File";
        mFileName += to_string(i+1);
        mFileName += ext;

        fileName = mFileName;

        if (!Helper::fileExist(fileName)) { // File is created only if it doesn't already exist

            if (isUnknownFile && !uknownFileWantsCommentHeader) {
                ofstream file;
                file.open(fileName);
                file.close();
            } else {
                CreateCommentHeader();
            }
            cout << fileName << " created!" << endl;
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
		cout << "Error" << endl;
	}
	return result;
}
