#ifndef CSV_READER_H
#define CSV_READER_H

#include <fstream>
#include <string>
#include "graph.h"

using namespace std;

class CSVReader
{
public:
	CSVReader();
	load(*Graph graph, string filename);	// Loads data from provided CSV file into graph
private:
};

#endif
