# Makefile for ASCIIGraph.

all: ASCIIGraph

ASCIIGraph: main.o userinput.o
	g++ -o ASCIIGraph main.o userinput.o

main.o: main.cpp
	g++ -c main.cpp

userinterface.o: userinput.cpp userinput.h
	g++ -c userinput.cpp userinput.h

clean:
	rm -rf ASCIIGraph *.o
