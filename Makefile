VPATH = ../include/bco/cg \
        ../include/bco/cg/api \
        ../include/bco/cg/api/facade \
        ../include/bco/cg/api/rest \
        ../include/bco/cg/infrastructure \
	../include/bco/cg/simulators \
        ../src \
        ../apps \
        ../tests \

PREFIX = $(prefix)

INCLUDE = simulator-facade.hpp simulator-resource.hpp \
          simulator-factory.hpp \
	  abstract-simulator.hpp \
	  distribution-model.hpp langmuir-model.hpp \
	  root-resource.hpp results.hpp \
          registry.hpp

SRC =     simulator-facade.cpp simulator-resource.cpp \
	  simulator-factory.cpp \
	  distribution-model.cpp langmuir-model.cpp \
          root-resource.cpp results.cpp \
          registry.cpp

APPS =	  cg-simulator.cpp

TESTS =   cg-test.cpp 

SOBJ = $(SRC:.cpp=.o)
LOBJ = $(SRC:.cpp=.lo)
TOBJ = $(TESTS:.cpp=.o)
TEXE = $(TESTS:.cpp=)
AOBJ = $(APPS:.cpp=.o)
AEXE = $(APPS:.cpp=)

CC = g++
LT = libtool
LNAME = bcocg
OPT = -O2 -ggdb -pthread
#OPT = -O3 -pthread -DNDEBUG

# For g++ >= 5.4
CFLAGS = -I../include -I/localdisk/local/include $(OPT) -Wall -std=c++14
LDFLAGS = -I../include -I/localdisk/local/include $(OPT) -Wall -std=c++14 -L.
#LIBS = -lm -l$(LNAME) -lcppcms -lbooster
LIBS = -lm -l$(LNAME) -L/localdisk/local/lib -lcppcms -L/localdisk/local/lib -lbooster
#LIBS = -lm -l$(LNAME) -lpthread -lboost_program_options
#CFLAGS = -I../include $(OPT) -Wall -std=c++11
#LDFLAGS = -I../include $(OPT) -Wall -std=c++11 -L.
#LIBS = -lm -l$(LNAME) -lboost_program_options

# All object files.
%.o : %.cpp $(INCLUDE)
	$(LT) --mode=compile $(CC) -c $(CFLAGS) $< -o $@

# All executables.
% : %.cpp $(INCLUDE)
	$(LT) --mode=link $(CC) $(LDFLAGS) $(LIBS) $< -o $@ -rpath $(PREFIX)/bin

lib : $(SOBJ)
	$(LT) --mode=link $(CC) $(CFLAGS) -o lib$(LNAME).la $(LOBJ) -rpath $(PREFIX)/lib 

tests: $(TEXE)
	echo "Done: tests"

apps: $(AEXE)
	echo "Done: apps"

all: lib tests apps
	echo "Done: all"

install-lib: lib
	echo "Installing libs"	
	$(LT) --mode=install install lib$(LNAME).la $(PREFIX)/lib

install-tests: tests
	echo "Installing tests"
	$(LT) --mode=install install $(TEXE) $(PREFIX)/bin

install-apps: apps
	echo "Installing apps"
	$(LT) --mode=install install $(AEXE) $(PREFIX)/bin

install: install-lib install-apps install-tests

docs: $(INCLUDE)
	cd ..;pwd;/usr/bin/doxygen Doxyfile;

clean-build :
	$(LT) --mode=clean \rm -r -f ../build/.libs/*
	$(LT) --mode=clean \rm -r -f ../build/.libs/*.*
	\rm -r -f ../build/.libs
	$(LT) --mode=clean \rm -r -f ../build/*

clean-tests :
	$(LT) --mode=clean \rm -r -f $(TEXE)

clean-lib :
	$(LT) --mode=clean \rm -r -f *.lo lib$(LNAME)*

clean-apps :
	$(LT) --mode=clean \rm -r -f $(AEXE)

clean-doxy:
	$(LT) --mode=clean \rm -r -f ../html/search/*
	- $(LT) --mode=clean rmdir --verbose ../html/search
	\rm -r -f ../html/search
	$(LT) --mode=clean \rm -r -f ../html/*.html
	$(LT) --mode=clean \rm -r -f ../html/*.js
	$(LT) --mode=clean \rm -r -f ../html/*.*
	- $(LT) --mode=clean \rm -r -f ../html/*

clean: clean-tests clean-lib clean-apps clean-build clean-doxy
	echo "Done: clean"
