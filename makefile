# Makefile for ASCIIGraph.

all: ASCIIGraph

ASCIIGraph: main.o userinput.o graph.o
	g++ -o ASCIIGraph main.o userinput.o graph.o

main.o: main.cpp
	g++ -c main.cpp

userinput.o: userinput.cpp userinput.h
	g++ -c userinput.cpp userinput.h

graph.o: graph.cpp graph.h
	g++ -c graph.cpp graph.h

clean:
	rm -rf ASCIIGraph *.o
