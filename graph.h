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
private:
	vector< vector<float> > data;
	string title;
	string vlabel;
	string hlabel;
	char plotting_char;
};

#endif
