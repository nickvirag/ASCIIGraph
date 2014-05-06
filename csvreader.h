#ifndef CSV_READER_H
#define CSV_READER_H

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "graph.h"
#include "pair.h"

using namespace std;

class CSVReadException : public exception {};

class CSVReader
{
public:
	CSVReader();
	void load(Graph* graph, string filename);	// Loads data from provided CSV file into graph
private:
	void addRecordToGraph(Graph* graph, string record);	// Adds this record to the graph
};

#endif
