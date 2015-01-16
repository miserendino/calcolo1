EXECUTABLES := luglio2008 febbraio2009
ROOT-CONFIG := $(shell root-config --cflags --glibs)
all:$(EXECUTABLES); 
luglio2008:luglio2008.cpp;@ $(CXX)  -g -pg $^ -o $@ $(LIBS) 
febbraio2009:febbraio2009.cpp; $(CXX) -D DEBUG -o $@ $^ $(ROOT-CONFIG)

.PHONY: clean
clean:;@ /bin/rm -f $(EXECUTABLES)

