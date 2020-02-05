// **************************************************************************** 
// File: OnlyFileBehavior.cpp 
// Author: Sergio Ortiz Paz 
// Created: Mon Feb  3 19:47:40 2020 
// Description: Implement the abstract class for first commd option 
// **************************************************************************** 

#include "../headers/OnlyFileBehavior.h"
#include "../headers/Helper.h"


#include <iostream>

using namespace std;

OnlyFileBehavior::OnlyFileBehavior() {
    //dataPath = Helper::getDataPath();
}


/* void OnlyFileBehavior::CreateCode() {
    cout << "Estoy en el metodo " << endl;
    cout << "y veo que dataPath es: " << dataPath << endl;
    string ext = Helper::getExtension("Sergio.java");
    cout << "La extension del archivo es: " << ext << endl;
    //string *data = blowCommentByExtensions(ext);
    blowCommentByExtensions(ext);
    //ICommandBehavior *kj;
    //data = kj->blowCommentByExtensions(ext);
    //cout << "initComment: " << *(data) << " endingComment: " << *(data + 1) << data->length() << endl;
    cout << "comment from  base: " << comment << " and commentClosureOpt from base: " << commentClosureOpt << endl;
} */



void OnlyFileBehavior::CreateCode() {
    // file name validation
    if (Helper::validateFileName(fileName)) {
        // Decision in case file already exist
        if (Helper::fileExist(fileName)){
            cout << "File " << fileName << " already exists in this directory. If you continue its content will be replaced" << endl;
            string chose;
            cout << "Do you want to continue (Y/n): ";
            cin >> chose;
            if (!Helper::questionReceptor(chose)) {
                return;
            }
        }
        string ext = Helper::getExtension(fileName);
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
        
        blowCommentByExtensions(ext);
        
        time_t now = time(0);
        char* dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0';
        dateOfCreation = string(dt);

        if (comment.empty()) {  // Check if type file is not supported in the program
            if (!Helper::RequireHeaderAssistance(fileName, comment, commentClosureOpt)) {
                ofstream file;
                file.open(fileName);
                file.close();
            } else {
                CreateCommentHeader();
            }
        } else {
            CreateCommentHeader();
        }
    } else {
        cout << fileName << " is not a valid file name. File name must be in this form 'filename.ext'" << endl;
    }

}

