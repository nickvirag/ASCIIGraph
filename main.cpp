/*
	ASCIIGraph - A commandline graphing utility.
	Written by Christopher K. Horton and Nicholas Virag.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "csvreader.h"
#include "graph.h"
#include "userinput.h"

using namespace std;

int main(int argc, const char* argv[])
{
	string filename, title, vlabel, hlabel, width, height, write;
	
	switch(argc)
	{
	case 1:
		// Ask the user for where input is coming from
		cout << "Please enter the CSV filename: ";
		getline(cin, filename);
		break;
	case 2:
		// The filename is supplied as the first argument
		filename = argv[1];
		break;
	default:
		// Incorrect usage
		cout << "Usage: ASCIIGraph [filename]" << endl;
		return 1;
	}
	
	// Get graph data
	Graph* graph = new Graph();
	CSVReader* reader = new CSVReader();
	try
	{
		reader->load(graph, filename);
	}
	catch(exception& e)
	{
		cout << "Cannot continue; unable to load data for graphing." << endl;
		return 2;
	}
	delete reader;
	
	// Get graph details
	cout << "Please enter the graph title: ";
	getline(cin, title);
	cout << "Please enter a vertical axis label: ";
	getline(cin, vlabel);
	cout << "Please enter a horizontal axis label: ";
	getline(cin, hlabel);
	cout << "Please enter graph width (in characters): ";
	getline(cin, width);
	cout << "Please enter graph height (in characters): ";
	getline(cin, height);
	
	graph->setTitle(title);
	graph->setVLabel(vlabel);
	graph->setHLabel(hlabel);
	graph->setConsoleDimensions( atoi( width.c_str( ) ), atoi( height.c_str( ) ) );

	cout << "Write to file? (Y/N): ";
	getline(cin, write);
	if( write == "Y" || write == "y" ){
		cout << "Enter file name and path: ";
		getline( cin, write );
		ofstream file;
		file.open( write.c_str( ) );
		file << graph->getGraph( );
		file.close( );
	}
	
	cout << '\n' << graph->getGraph( );
	
	delete graph;
	
	return 0;
}
