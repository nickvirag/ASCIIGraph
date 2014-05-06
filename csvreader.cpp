#include "csvreader.h"

using namespace std;

CSVReader::CSVReader()
{
}

void CSVReader::load(*Graph graph, string filename)
{
	fstream input;
	input.open(filename.c_str());
	if(input)
	{
		string record;
		int columns;
		
		getline(input, record);
		columns = determineColumns(record);
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

int CSVReader::determineColumns(string record)
{
	// Report the number of columns as the number of commas + 1
	int commas = 0;
	for(unsigned int i = 0; i < record.size(); i++)
		if(record.at(i) == ",")
			commas++;
	return commas + 1;
}

void CSVReader::addRecordToGraph(*Graph graph, string record)
{
	// Split the record up according to commas and convert each field to float
	vector<float> fields;
	char* field_token;
	
	field_token = strtok(record.c_str(), ",");
	while(field_token != NULL)
	{
		fields.push_back(atof(field_token));
		field_token = strtok(record.c_str(), ",");
	}
	
	graph->addRecord(fields);
}
