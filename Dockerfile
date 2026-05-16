FROM ubuntu:latest

RUN apt -y update && apt -y install g++ dos2unix cmake

COPY . /usr/src/cnh

WORKDIR /usr/src/cnh

# Change ending lines of files for possible issues when building app CRLF to LF
RUN find . -type f -print0 | xargs -0 dos2unix || true

RUN ./linux_release.sh

RUN cmake --install release
