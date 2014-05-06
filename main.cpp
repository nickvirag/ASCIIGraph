/*
	ASCIIGraph - A commandline graphing utility.
	Written by Christopher K. Horton and Nicholas Virag.
*/

#include <iostream>
#include <string>
#include "csvreader.h"
#include "graph.h"
#include "userinput.h"

using namespace std;

int main(int argc, const char* argv[])
{
	string filename, title, vlabel, hlabel;
	
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
	
	graph->setTitle(title);
	graph->setVLabel(vlabel);
	graph->setHLabel(hlabel);
	
	cout << '\n' << graph->getGraph( );
	
	//delete graph;
	
	return 0;
}
