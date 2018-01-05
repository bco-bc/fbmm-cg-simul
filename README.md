# Chromatography Simulator

## Dependencies

1. CppCMS — C++ Web Framework: http://cppcms.com

## Build instructions

1. mkdir ./build
2. cd build
3. make prefix=/usr/local -f ../Makefile
4. make install

Replace the value for prefix, if needed. Upon completion, a library 'libbcocg' is installed in $(prefix)/lib and an executable 'cg-simulator' is installed in $(prefix)/bin.

## Running

From the CLI, enter

cg-simulator -c config.js

Here, config.js is a JSON-based configuration file to set up the RESTful endpoint.

