EXECUTABLES := luglio2008 febbraio2009 gennaio2009 foo
ROOT-CONFIG := $(shell root-config --cflags --glibs)
all:$(EXECUTABLES); 
luglio2008:luglio2008.cpp;@ $(CXX)  -g -pg $^ -o $@ $(LIBS) 
foo:foo.cpp; $(CXX) -g -Wall -std=c++11 -o $@ $^ $(LIBS)
febbraio2009:febbraio2009.cpp; $(CXX) -D DEBUG -o $@ $^ $(ROOT-CONFIG)
gennaio2009:gennaio2009.cpp; $(CXX) -std=c++11 -D DEBUG -o $@ $^ $(ROOT-CONFIG)
.PHONY: clean
clean:;@ /bin/rm -f $(EXECUTABLES)

