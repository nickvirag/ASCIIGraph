#include "csvreader.h"

using namespace std;

CSVReader::CSVReader()
{
}

void CSVReader::load(Graph* graph, string filename)
{
	fstream input;
	input.open(filename.c_str());
	if(input)
	{
		string record;
		
		getline(input, record);
		while(input)
		{
			addRecordToGraph(graph, record);
			getline(input, record);
		}
	}
	else
		cout << "Could not open the CSV file for reading." << endl;
	input.close();
}

void CSVReader::addRecordToGraph(Graph* graph, string record)
{
	// Split the record up according to commas and convert each field to float
	char* record_c = new char[record.length() + 1];
	Pair data;
	
	strcpy(record_c, record.c_str());
	data.x = atof(strtok(record_c, ","));
	data.y = atof(strtok(NULL, ","));
	
	graph->addData(data);
}
