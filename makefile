# Makefile for ASCIIGraph.

OBJECTS=main.o userinput.o graph.o csvreader.o
EXECUTABLE=ASCIIGraph

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)

main.o: main.cpp
	g++ -c main.cpp

userinput.o: userinput.cpp userinput.h
	g++ -c userinput.cpp userinput.h

graph.o: graph.cpp graph.h pair.h
	g++ -c graph.cpp graph.h pair.h

csvreader.o: csvreader.cpp csvreader.h pair.h
	g++ -c csvreader.cpp csvreader.h pair.h

clean:
	rm -rf $(EXECUTABLE) *.o *.gch
