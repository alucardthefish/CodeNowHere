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
  int numOfFiles = (args["<numfiles>"].isString()) ? stoi(args["<numfiles>"].asString()) : 0;
  bool optThis = args["this"].asBool();
  bool optThese = args["these"].asBool();
  bool optBunch = args["bunchof"].asBool();
  
  cnh::arguments structData = cnh::init(fileName, author, description, hasCopyRight, fileNames, bunchExt, numOfFiles, optThis, optThese, optBunch);
  
  return structData;
}

int main(int argc, char * argv[]) {

    std::map<std::string, docopt::value> args
        = docopt::docopt(USAGE,
                         { argv + 1, argv + argc },
                         true,               // show help if requested
                         "CodeNowHere 2.1.1"); // version string
    
    CodeNowHere codeNowHere(getDocoptAsArgStructure(args));
    // Testing purposes
    // for (auto const& arg : args)
    // {
    //   std::cout << arg.first << " - " << arg.second << std::endl;
    // }
    // return 0;
    std::cout << "argc: " << argc << std::endl;
    // for (auto const& arg : argv) {
    //   std::cout << "element: " << arg << std::endl;
    // }
    std::cout << "argv + 1: " << argv << std::endl;
    codeNowHere.Execute();
    cnh::arguments my_arguments = getDocoptAsArgStructure(args);
    std::cout << "file name: " << my_arguments.fileName << std::endl;
    if (argc > 2) {
      time_t now = time(0);
      char* dt = ctime(&now);
      dt[strlen(dt) - 1] = '\0';
      std::string dateCreation = std::string(dt);

      tm *ltm = localtime(&now);
      int year = 1900 + ltm->tm_year;
      std::cout << "--------Checking new approach--------" << std::endl;
      CnhEngine engine;
      auto templates = engine.FindTemplates(my_arguments.fileName);
      engine.LoadDataFile("data.json");
      engine.LoadDataValue("cnh_date", dateCreation);
      engine.LoadDataValue("cnh_file", my_arguments.fileName);
      engine.LoadDataValue("cnh_name", my_arguments.author);
      auto result = engine.RenderFile(std::get<0>(templates[0]).string());
      for (auto& line: result) {
        std::cout << line << "\n";
      }
    } else {
      std::cout << "" << std::endl;
      std::cout << "argc is not 2" << std::endl;
    }
    return 0;
}
