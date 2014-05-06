#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include "pair.h"

using namespace std;

class Graph
{
public:
	Graph();
	void setTitle(string title);
	void setVLabel(string vlabel);
	void setHLabel(string hlabel);
	void setPlottingChar(char plotting_char);
	string getTitle();
	string getVLabel();
	string getHLabel();
	char getPlottingChar();
	void addData(float x, float y);
	void addData(Pair record);
private:
	vector<Pair> data;
	float x_max;
	float x_min;
	float y_max;
	float y_min;
	string title;
	string vlabel;
	string hlabel;
	char plotting_char;
	void updateMaxMin(float x, float y);
	void incrementRows();	// Increase number of rows by one
};

#endif
