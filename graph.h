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
private:
	vector< vector<float> > data;
	vector<float> col_max;
	vector<float> col_min;
	string title;
	string vlabel;
	string hlabel;
	char plotting_char;
	void updateColMaxMin(int col, float value);
};

#endif
