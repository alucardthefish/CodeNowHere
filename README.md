<h1 align="center"> CodeNowHere </h1>

<p align="center">
    <img src="https://images2.imgbox.com/03/0a/D5blA5f4_o.jpg" />
</p>

CLI application to create almost any programming language files from your terminal! It has been developed to be used in any bash or shell, also in IDEs, text editors with console or terminal integrated. The app is developed in C++ and currently is made for Linux Systems (Debian/Ubuntu with gcc), Windows (10 and 11 with vs2022), and, Mac (with clang). But, with your help and contribution we together could maintain the program on this systems.

## What is the idea?
The idea is to develop a Command Line Interface program for allowing CLI lovers to create their favorite code files wherever directory they are. The file will be generated with a comment header which will contain information about the file and the client. For example, File Name, Date of Creation, Author, and a brief description that should be optional and provided by the user. Although, depending on the type of language, it creates a trivial sample code like hello world in a main function or in a proper function. After that, you can open it with your favorite editor (i.e vi, vim, etc.). The CLI interface code relies on [docopt.cpp](https://github.com/docopt/docopt.cpp)  library for making easier the creation of command-line interfaces.
For more information on `docopt.cpp`, please see [this page](http://docopt.org/).

This is a very humble project. I am not using any framework to develop this project. However, originally it uses `autotools` for generating the configuration files and the *Makefile* to build and install the project on linux systems but now we changed it to use `cmake` in order to be able to build and install in multiple system platforms. I am learning while doing, so may there be lots of mistakes and errors in designing and coding. I'll be thankful for any recommendation for improving the code.

## Linux Minimum Requirements

* C++11 (FOR VERSION 2.1.1 and below)
* C++20 (FOR VERSION 3.0.0 and below)
* cmake

### Installing linux dependencies (Debian)

```sh
$ sudo apt update
$ sudo apt install g++
$ sudo apt install cmake
```

To get the code, build, and install the CLI app; follow the commands below:


## How to download and build CNH on Linux

```sh
$ git clone https://github.com/alucardthefish/CodeNowHere.git
$ cd CodeNowHere
$ . ./linux_release.sh
```

## How to install CNH on Linux/MacOS

After building you can install it in your machine this way:

```sh
$ sudo cmake --install release
```

*make install* can be reverted through the uninstall command:
```sh
$ sudo cmake --build release --target uninstall
```

### (FOR VERSION 2.1.1 and below)
A bash script `build_local.sh` is provided to compile it locally in the build directory. You can edit it with your compiler.

```sh
$ ./build_local.sh
$ cd build
# Example
$ ./cnh this File.ext -a "Author One" -d "Description one"
```

## Windows Minimum Requirements

* VS2022
* cmake

### Installing dependencies on Win

1. Download and install Visual Studio from: [here](https://visualstudio.microsoft.com/vs/community/)

2. Download and install cmake from: [here](https://cmake.org/download/)


## How to download and build CNH on Windows

```sh
$ git clone https://github.com/alucardthefish/CodeNowHere.git
$ cd CodeNowHere
$ ./win_release.cmd
```

## How to install CNH on Windows

After building you can install it in your machine this way:

You need to open a CMD or PowerShell as administrator and run the following command standing on the root of the project.

```PS
$ cmake --install build
```

Optional: add the cnh folder path to the PATH_ENV after completing the installation in order to have access to CNH in the whole windows system.

*make install* can be reverted through the uninstall command: 
```PS
$ cmake --build build --target uninstall
```
## Docker environment

You can run the docker image for this project which will install the dependencies, build the app and install it.

First step is to build the docker image: (Make sure you're standing on project base folder called CodeNowHere)

```sh
$ docker build . -t cnh:1.0.0
```

Second step is to run a container from the built image

```sh
$ docker run -it --rm cnh:1.0.0 bash
```

From here you can have access to a bash console and create your files using the app.

Optional: if you want to mirror the code with docker container working directory. Try this as below

```sh
$ docker run -it -v $(pwd):/usr/src/cnh --rm cnh:1.0.0 bash
```

## Install/Uninstall on Linux from release tar (With autotools) FOR VERSION 2.1.1 and below

You can download a version package from [release page](https://github.com/alucardthefish/CodeNowHere/releases). The package will have this format: cnh-x.y.z.tar.gz (x, y, and z are numbers).

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

4. To uninstall try running from the source directory where you ran make install:

```sh
$ sudo make uninstall
```

# Install/Uninstall from installers FOR VERSION 3.0.0

You can download the installer of your preference from [release v3.0.0 page](https://github.com/alucardthefish/CodeNowHere/releases/tag/v3.0.0).

## Linux Debian AMD64

1. From the terminal, navigate to the directory where installer with extension .deb has been downloaded.

2. Type the following to install CNH in your system:

```sh
$ sudo dpkg -i cnh-linux-3.0.0-amd64.deb
```
3. then after installed you need to run the following command to complete the installation:

```sh
$ source /etc/profile.d/cnh.sh
```

4. To uninstall type in a terminal the following:

```sh
$ sudo dpkg -r CodeNowHere
```

## Windows

1. Go to the downloads folder or the location where the `cnh-windows-3.0.0.exe` file was downloaded and execute it by double clicking it.

2. After finish the installation process, add the executable path to the ENV VAR path (something like example below):

```sh
C:\Program Files\CodeNowHere 3.0.0\bin
```

3. To uninstall you can use the uninstaller executable you can find in the app folder or use the Windows Control Panel > Programs:


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

* For creating various code files at once you can do it by passing their names as follows:

```sh
$ cnh these MyFileA.py MyFileB.py MyFileC.cpp -a "John Doe" --cr
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
* Bash
* Boo
* C
* C-INTERCAL
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
* Elixir
* Elm
* Erlang
* Euphoria
* F#
* Factor
* Falcon
* Fortran
* Fp
* Gap
* Gnuplot
* Go
* Gosu
* Groovy
* Haskell
* Html
* Icon
* Imba
* Io
* J
* Janet
* Java
* JavaScript
* Julia
* Json
* Kotlin
* Logo
* Lua
* Nemerle
* ObjectiveC
* Pawn
* Pascal
* Perl
* Php
* Picat
* PL/SQL
* Prolog
* Pony
* Python
* Qore
* R
* Ruby
* Rust
* Scala
* Scheme
* Sql
* Swift
* Toml
* VisualBasic
* Xml
* Yaml

Whether you enter a different programming language from the list above or an unknown file into the program, it will ask you for the inline comment character to create the header commentary. Otherwise, the comment header is omitted.

# Tests

Project uses the Google Test library for Unit Testing locally as part of the code in the submodule googletest. For testing, go to tests/ directory and write some tests.

To run the tests; type the following from base folder /

### Run tests (FOR VERSION 2.1.1 and below)

```bash
$ make check
```

### Run tests (FOR VERSION 3.0.0)

1. **Build the project**:
    * Navigate to the project directory and run the following commands to build the project and the test executable:
        ```bash
        $ mkdir build
        $ cd build
        $ cmake ..
        $ make
        ```
2. **Run the Tests**:
    * After building the project, you can run the test executable to execute the tests:
        ```bash
        $ ./tests/AllTests
        ```
3. **Using CTests**:
    * Alternatively, you can use CTest to run the tests:
        ```bash
        $ ctest
        ```

# Contribution

Please read our [Contributing guidelines](./.github/CONTRIBUTING.md), and [Code of Conduct](CODE_OF_CONDUCT.md).

Feel free to create issues and Pull Requests for improving this project. For instance, you can support it extending this utility adding more programming languages options, requesting new features, and reporting bugs.
