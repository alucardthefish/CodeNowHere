<h1 align="center"> CodeNowHere </h1>

<p align="center">
    <img src="https://images2.imgbox.com/03/0a/D5blA5f4_o.jpg" />
</p>

CLI application to create almost any programming language files from your terminal! It's thought to use in any bash or shell, also in IDEs, text editors with console or terminal integrated. The app is developed in C++ and currently is made for Linux Systems. But, with your help and contribution we together could extend this to other type of systems.

## What is the idea?
The idea is to develop a Command Line Interface program for allowing CLI lovers to create their favorites code files wherever directory they are. The file will be generated with a comment header which will contain information about the file and the client. For example, File Name, Date of Creation, Author, and a brief description.

This is a very humble project. I am not using any framework to develop this project. However, you can use *make* to build the project. I am learning while doing, so may be lots of mistakes and errors in designing and coding. I'll be thankful for any recommendation for improving the code.

To get the code, build, and install the CLI app; follow the commands below:

## How to download and build on linux

<pre>
clone https://github.com/alucardthefish/CodeNowHere.git
cd CodeNowHere
make
make install
</pre>

## How to install on linux

After building you can install it in your machine this way:

<pre>
make install
</pre>

*make install* can be reconfigure depending on your linux machine. Edit the makefile file in the section install according to the path to your private binaries. This can be check in the .profile file

<pre>
cat ~/.profile
</pre>

After that, you can update the makefile with the path for private binaries in the copy (cp) and rename/move (mv) commands. Finally to make the executable available in your shell terminal type in console something like this for avoid restarting your machine:

<pre>
source ~/.profile
</pre>

Or whatever the path to your .profile is.

## Under construction..
