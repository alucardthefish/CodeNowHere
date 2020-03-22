<h1 align="center"> CodeNowHere </h1>

<p align="center">
    <img src="https://images2.imgbox.com/03/0a/D5blA5f4_o.jpg" />
</p>

CLI application to create almost any programming language files from your terminal! It has been developed to be used in any bash or shell, also in IDEs, text editors with console or terminal integrated. The app is developed in C++ and currently is made for Linux Systems. But, with your help and contribution we together could extend this to other type of systems.

## What is the idea?
The idea is to develop a Command Line Interface program for allowing CLI lovers to create their favorites code files wherever directory they are. The file will be generated with a comment header which will contain information about the file and the client. For example, File Name, Date of Creation, Author, and a brief description. Although, depends on the type of language, it creates a trivial sample code like hello world in a main function or in a proper function. After that, you can open it with your favorite editor (i.e vi, vim, etc.). The CLI interface code relies on [docopt.cpp](https://github.com/docopt/docopt.cpp)  library for making easier the creation of command-line interfaces.
For more information on `docopt.cpp`, please see [this page](http://docopt.org/).

This is a very humble project. I am not using any framework to develop this project. However, it uses autotools for generating the configuration files and the *Makefile* to build and install the project. I am learning while doing, so may there be lots of mistakes and errors in designing and coding. I'll be thankful for any recommendation for improving the code.

## Linux Minimum Requirements

* C++11
* autotools (autoconf, automake, libtool)

### Installing autotools

```sh
$ sudo apt update
$ sudo apt install autotools-dev
$ sudo apt install autoconf
$ sudo apt install libtool
```

To get the code, build, and install the CLI app; follow the commands below:

## How to download and build on Linux

```sh
$ git clone https://github.com/alucardthefish/CodeNowHere.git
$ cd CodeNowHere
$ git submodule init
$ git submodule update
$ git config submodule.googletest.ignore untracked
$ ./autogen.sh
$ ./configure
$ make
```

## How to install on Linux

After building you can install it in your machine this way:

```sh
$ sudo make install
```

*make install* can be reverted through the uninstall command: 
```sh
$ sudo make uninstall
```

In the case you are building the project with an old C++ compiler and get an error message like this:

`Error this file requires compiler and library support for the ISO C++ 2011 standard. This support may be enabled
with the -std=c++11 or -std=gnu++11 compiler options.`

Then, you can run the config file this way:

```sh
$ ./configure CXXFLAGS="-std=gnu++11"
```

A bash script `build_local.sh` is provided to compile it locally in the build directory. You can edit it with your compiler.

```sh
$ ./build_local.sh
$ cd build
# Example
$ ./cnhtest File.ext -a "Author One" -d "Description one"
```

## Install on Linux from release tar

You can download a version package from [release page](https://github.com/alucardthefish/CodeNowHere/releases). The package will have this format: cnh-x.y.z.tar.gz (x, y, adn z are numbers).

1. From the terminal, change to the directory where cnh-x.y.z.tar.gz has been downloaded.
2. Type the following to extract the file to the current directory: 

```sh 
$ tar -zxvf cnh-x.y.z.tar.gz 
```
3. then install:

```sh 
$ ./configure CXXFLAGS="-std=gnu++11"
$ sudo make install
```

## Usage

Type in shell: 

```sh
$ cnh --help
```

```sh
Usage:
      cnh this <filename> [-a <author>] [-d <desc>] [--cr]
      cnh these <filenames>... [-a <desc>] [--cr]
      cnh bunchof <numfiles> [--ext=<fileext>] [--author | -a <author>]
      cnh (-h | --help)
      cnh --version
      

    Options:
      -h --help                       Show this screen.
      --version                       Show version.
      -a <author>, --author <author>  Set the file author.
      -d <desc>, --desc <desc>        Set the file description.
      --cr                            Set a copyright line to comment header.
      --ext=<fileext>                 File extension [default: .cpp]
```

*Filename* is mandatory. Depending on the extension file it will create the header commentary.

### Examples:

* Creating a python code file
```sh
$ cnh this sample.py
```

cnh generates a python file named `sample.py` with the following header comment:
```python
# **************************************************************************** 
# File: sample.py
# Author: UserName
# Created: Sun Jan  5 03:18:05 2020
# Description: 
# **************************************************************************** 


def main():
    print("Hello World!")


if __name__ == "__main__":
    main()



```

If option -a or --author is not passed, it takes the username from the system by default.

* Creating a code file in C++ with options arguments
```sh
$ cnh this sample.cpp -a "John Doe" -d "Sample of code file creation"
```

cnh generates a c++ file named `sample.cpp` with the following header comment:

```c++
// **************************************************************************** 
// File: sample.cpp
// Author: John Doe
// Created: Sun Jan  5 03:27:15 2020
// Description: Sample of code file creation
// ****************************************************************************

#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {
    cout << "Hello World" << endl;
    return 0;
}

```

* Adding copyright comment with --cr option:

```sh
$ cnh this sample.cpp -a "John Doe" -d "Sample of code file creation" --cr
```

The output would is shown below:

```c++
// **************************************************************************** 
// File: sample.cpp 
// Author: John Doe 
// Created: Thu Feb 20 17:23:41 2020 
// Copyright (c) 2020 John Doe. All rights reserved. 
// Description: Sample of code file creation 
// **************************************************************************** 


#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {
    cout << "Hello World" << endl;
    return 0;
}
```

* For creating various code files at once you can do it passing their names as follows:

```sh
$ cnh these MyFileA.py MyFileB.py MyFileC.py -a "John Doe" --cr
```

* For creating a number of code files at once without specifying names only the extension file:

```sh
$ cnh bunchof 5 --ext .py
```

The created files come with blank description in their comment headers.

## Markup and Programing Languages Supported by Now

* Ada
* Agda
* Alef
* AppleScript
* Awk
* B
* Boo
* C
* C#
* C++
* Ceylon
* Clojure
* Cobol
* Cobra
* CoffeeScript
* ColdFusion
* Crystal
* Css
* D
* Dart
* E
* ECMAScript
* Egison
* Elm
* Erlang
* Euphoria
* F#
* Factor
* Fortran
* Go
* Gosu
* Html
* Imba
* Janet
* Java
* JavaScript
* Json
* Kotlin
* Lua
* ObjectiveC
* Pawn
* Perl
* Php
* Picat
* Python
* Qore
* Ruby
* Rust
* Sql
* VisualBasic
* Xml
* Yaml

Whether you enter a different programming language from the list above or an unknown file into the program, it will ask you for the inline comment character to create the header commentary. Otherwise, the comment header is omitted.

# Tests

Project uses the Google Test library for Unit Testing locally as part of the code in the submodule googletest. For testing, go to tests/ directory and write some tests.

To run the tests; type the following from base folder /

```bash
$ make check
```

# Contribution

Feel free to create issues and Pull Requests for improving this project. For instance, you can support it extending this utility adding more programming languages options and features.
