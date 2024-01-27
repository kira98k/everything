FROM ubuntu:latest

# Update Repos
RUN apt-get -y update

# C & C++ Compiler & Debugger
RUN apt-get install -y gcc g++ make

# Environment Variables
ENV PATH=/code:$PATH

# Working Directory
WORKDIR /code
