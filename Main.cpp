#include <iostream>
#include <string>
#include "headers/CodeNowHere.h"

using namespace std;

int main(int argc, char * argv[]) {
    if ((argc % 2) != 0){
        // Bad input
        cout << "Some option is missing or some parameters are invalid! Check help typing cnw -help" << endl;
        return -1;
    }
    if (argc < 2) {
        // Print usage text in console
        cout << "Print usage text in console" << argc << endl;
    } else {
        cout << "Capture input from console and process it" << argc  << endl;
        // Capture input from console and process it
        CodeNowHere cnh;
        cnh.captureConsoleInput(argc, argv);
        cnh.createCode();
    }
    return 0;
}