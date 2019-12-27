#include <iostream>
#include <string>
#include "headers/CodeNowHere.h"

using namespace std;

int main(int argc, char * argv[]) {
    Helper helper;
    if (argc < 2) {
        // Print usage text in console
        //cout << "Print usage text in console" << argc << endl;
        cout << helper.getUsage() << endl;
    } else if ((argc % 2) != 0){
        // Bad input
        //cout << "Some option is missing or some parameters are invalid! Check help typing cnw -help" << endl;
        cout << helper.getBadInput() << endl;
        return -1;
    } else {
        // Capture input from console and process it
        CodeNowHere cnh;
        if (argc == 2) {
            string informativeOption = string(argv[1]);
            if (informativeOption == "-h" || informativeOption == "--help") {
                cout << helper.getUsage() << endl;
            } else if (informativeOption == "--version") {
                cout << helper.getVersion() << endl;
            } else {
                cnh.captureConsoleInput(argc, argv);
                cnh.createCode();
            }
        } else {
            cnh.captureConsoleInput(argc, argv);
            cnh.createCode();
        }
        
        cnh.captureConsoleInput(argc, argv);
        cnh.createCode();
    }
    return 0;
}