#include <iostream>
#include <string>
#include "headers/CodeNowHere.h"
#include "headers/docopt.h"
#include "headers/cnh_structs.h"

#include "headers/cnhengine.h"

using namespace std;

static const char USAGE[] =
R"(Code Now Here (CNH).

    Usage:
      cnh this <filename> [-a <author>] [-d <desc>] [--cr]
      cnh these <filenames>... [-a <author>] [--cr]
      cnh bunchof <numfiles> [--ext=<fileext>] [-a <author>]
      cnh (-h | --help)
      cnh --version


    Options:
      -h --help                       Show this screen.
      --version                       Show version.
      -a <author>, --author <author>  Set the file author.
      -d <desc>, --desc <desc>        Set the file description.
      --cr                            Set a copyright line to comment header.
      --ext=<fileext>                 File extension [default: .cpp]
)";

cnh::arguments getDocoptAsArgStructure(map<string, docopt::value> args) {
  std::string fileName = (args["<filename>"].isString()) ?  args["<filename>"].asString() : "";
  std::string author = (args["--author"].isString()) ? args["--author"].asString() : "";
  std::string description = (args["--desc"].isString()) ? args["--desc"].asString() : "";
  bool hasCopyRight = args["--cr"].asBool();
  std::vector<std::string> fileNames = args["<filenames>"].asStringList();
  std::string  bunchExt = args["--ext"].asString();
  
  // Validate CLI input: Parse numfiles with error handling
  int numOfFiles = 0;
  if (args["<numfiles>"].isString()) {
    try {
      int parsed = stoi(args["<numfiles>"].asString());
      // Validate parsed value is non-negative
      if (parsed < 0) {
        cerr << "Error: Number of files must be non-negative." << endl;
        numOfFiles = 0;
      } else {
        numOfFiles = parsed;
      }
    } catch (const std::invalid_argument& e) {
      cerr << "Error: Invalid number of files argument. Must be a valid integer." << endl;
      numOfFiles = 0;
    } catch (const std::out_of_range& e) {
      cerr << "Error: Number of files argument is out of range." << endl;
      numOfFiles = 0;
    }
  }
  
  bool optThis = args["this"].asBool();
  bool optThese = args["these"].asBool();
  bool optBunch = args["bunchof"].asBool();

  cnh::arguments structData = cnh::init(
    fileName,
    author,
    description,
    hasCopyRight,
    fileNames,
    bunchExt,
    numOfFiles,
    optThis,
    optThese,
    optBunch
  );

  return structData;
}

int main(int argc, char * argv[]) {

    std::map<std::string, docopt::value> args
        = docopt::docopt(USAGE,
                         { argv + 1, argv + argc },
                         true,               // show help if requested
                         "CodeNowHere 3.0.0"); // version string

    CodeNowHere codeNowHere(getDocoptAsArgStructure(args));
    // Testing purposes
    // for (auto const& arg : args)
    // {
    //   std::cout << arg.first << " - " << arg.second << std::endl;
    // }
    // return 0;
    codeNowHere.Execute();

    return 0;
}
