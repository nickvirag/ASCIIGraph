#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

using namespace std;

class Graph
{
public:
	Graph();
	void setDimensions(int rows, int cols);
	void setTitle(string title);
	void setVLabel(string vlabel);
	void setHLabel(string hlabel);
	void setPlottingChar(char plotting_char);
	string getTitle();
	string getVLabel();
	string getHLabel();
	char getPlottingChar();
	void setData(float value, int row, int col);
	void addRecord(vector<float>& record);	// Adds a row to the graph
private:
	vector< vector<float> > data;
	vector<float> col_max;
	vector<float> col_min;
	string title;
	string vlabel;
	string hlabel;
	int num_rows;
	int num_cols;
	char plotting_char;
	void updateColMaxMin(int col, float value);
	void incrementRows();	// Increase number of rows by one
};

#endif
