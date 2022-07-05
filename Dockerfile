FROM ubuntu:latest

RUN apt -y update && apt -y install g++ dos2unix autotools-dev autoconf libtool make git

COPY . /usr/src/cnh

WORKDIR /usr/src/cnh

# Change ending lines of files for possible issues when building app CRLF to LF
RUN find . -type f | xargs dos2unix

RUN git submodule init

RUN git submodule update

RUN git config submodule.googletest.ignore untracked

RUN ./autogen.sh

RUN ./configure

RUN make && make install
