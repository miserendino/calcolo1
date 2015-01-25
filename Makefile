EXECUTABLES := luglio2008 febbraio2009 gennaio2009 foo prova
ROOT-CONFIG := $(shell root-config --cflags --glibs)
FLAGS := -v -fmessage-length=0 -std=gnu++11
all:$(EXECUTABLES); 
luglio2008:luglio2008.cpp;@ $(CXX)  -g -pg $^ -o $@ $(LIBS) $(FLAGS)
foo:foo.cpp; $(CXX) -g -Wall -o $@ $^ $(LIBS) $(FLAGS)
prova:prova.cpp; $(CXX) -g -Wall -o $@ $^ $(LIBS) $(FLAGS)
febbraio2009:febbraio2009.cpp; $(CXX) -D DEBUG -o $@ $^ $(ROOT-CONFIG) $(FLAGS)
gennaio2009:gennaio2009.cpp; $(CXX) -D DEBUG -o $@ $^ $(ROOT-CONFIG) $(FLAGS)
.PHONY: clean
clean:;@ /bin/rm -f $(EXECUTABLES)

