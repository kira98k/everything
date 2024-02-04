FROM ubuntu:latest

# Update Repos
RUN apt-get -y update

# Make, C, C++, Python3 & Rust
RUN apt-get install -y make gcc g++ python3 rustc

# Environment Variables
ENV PATH=/code:$PATH

# Working Directory
WORKDIR /code
