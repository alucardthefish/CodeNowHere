#include <iostream>
#include <string>
#include "headers/CodeNowHere.h"
#include "headers/docopt.h"

using namespace std;

static const char USAGE[] =
R"(Code Now Here (CNH).

    Usage:
      cnh <filename> [--author | -a <author>] [--desc | -d <desc>] [--cr]
      cnh (-h | --help)
      cnh --version
      

    Options:
      -h --help                       Show this screen.
      --version                       Show version.
      -a <author>, --author <author>  Set the file author.
      -d <desc>, --desc <desc>        Set the file description.
      --cr                             Set a copyright line to comment header.
)";

int main(int argc, char * argv[]) {

    std::map<std::string, docopt::value> args
        = docopt::docopt(USAGE,
                         { argv + 1, argv + argc },
                         true,               // show help if requested
                         "CodeNowHere 1.0"); // version string
    
    CodeNowHere cnh = CodeNowHere(args);
    cnh.Execute();
    
    return 0;
}