<h1 align="center"> CodeNowHere </h1>

<p align="center">
    <img src="https://images2.imgbox.com/03/0a/D5blA5f4_o.jpg" />
</p>

CLI application to create almost any programming language files from your terminal! It's thought to use in any bash or shell, also in IDEs, text editors with console or terminal integrated. The app is developed in C++ and currently is made for Linux Systems. But, with your help and contribution we together could extend this to other type of systems.

## What is the idea?
The idea is to develop a Command Line Interface program for allowing CLI lovers to create their favorites code files wherever directory they are. The file will be generated with a comment header which will contain information about the file and the client. For example, File Name, Date of Creation, Author, and a brief description. Although, depends on the type of language it creates a trivial sample code like hello world in a main function or in a proper function.

This is a very humble project. I am not using any framework to develop this project. However, you can use *make* to build the project. I am learning while doing, so may there be lots of mistakes and errors in designing and coding. I'll be thankful for any recommendation for improving the code.

To get the code, build, and install the CLI app; follow the commands below:

## How to download and build on linux

<pre>
clone https://github.com/alucardthefish/CodeNowHere.git
cd CodeNowHere
make
</pre>

## How to install on linux

After building you can install it in your machine this way:

<pre>
make install
</pre>

*make install* can be reconfigure depending on your linux machine. Edit the makefile file in the section install according to the path to your private binaries. This can be check in the .profile file in your home directory.

<pre>
cat ~/.profile
</pre>

After that, you can update the makefile with the path for private binaries in the copy (cp) and rename/move (mv) commands. Finally to make the executable available in your shell terminal type in console something like this for avoid restarting your machine:

<pre>
source ~/.profile
</pre>

Or whatever the path to your .profile is.

## Usage

Type in shell: 

<code>$> cnh --help</code>

<pre>
Usage:
        cnh (&lt;filename&gt;) [-option &lt;argument&gt;]...
        cnh (-h | --help)
        cnh --version
        
Options:
        -h --help       Show this screen.
        --version       Show version.
        -a --author     Specify the author of the code.
        -d --desc       Specify a brief description of the file.
</pre>

*Filename* is mandatory. Depend on the extension file it will create the header comment.

### Examples:

Create a code file for python
<pre>cnh sample.py</pre>

cnh generates a python file named *sample.py* with the following header comment:
<pre>
# **************************************************************************** 
# File: sample.py
# Author: 
# Created: Sun Jan  5 03:18:05 2020
# Description: 
# **************************************************************************** 


def main():
    print("Hello World!")


if __name__ == "__main__":
    main()


</pre>

Create a code file in C++ with options arguments
<pre>cnh sample.cpp -a "John Doe" -d "Sample of code file creation"</pre>

cnh generates a c++ file named *sample.cpp* with the following header comment:
<pre>
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

</pre>

## Programing Languages Supported by Now

* Ada
* C
* C++
* Go
* Java
* JavaScript
* Php
* Python
* Ruby

If a different programming language or unknown file for the program is passed, it will ask you for the inline comment character to create the header commentary.

## Contribution

Feel free to create issues and Pull Requests for improving this project. For instance, you can support it extending this utility adding more programming languages options.