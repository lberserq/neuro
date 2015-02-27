CXX=g++
LD=g++
PARSEDIR=../src/parsers
CXXFLAGS=-std=c++11 -I$(PARSEDIR)
all: nbetest

nbeparser.o: $(PARSEDIR)/nbeparser.cpp $(PARSEDIR)/nbeparser.h
	$(CXX) $(CXXFLAGS) -c $(PARSEDIR)/nbeparser.cpp -o nbeparser.o
nbetest.o: nbetest.cpp parsertests.h $(PARSEDIR)/nbeparser.h

nbetest:nbetest.o nbeparser.o
	$(CXX) $(CXXFLAGS) nbetest.o nbeparser.o -o nbetest
clean:
	rm -rf *.o
	rm -rf nbetest