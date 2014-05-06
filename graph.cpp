#include "graph.h"

Graph::Graph()
{
}

void Graph::setDimensions(int rows, int cols)
{
	data.resize(rows);
	for(int i = 0; i < rows; i++)
	{
		data.at(i).resize(cols);
	}
	col_max.resize(cols);
	col_min.resize(cols);
	num_rows = rows;
	num_cols = cols;
}

void Graph::setTitle(string title)
{
	this->title = title;
}

void Graph::setVLabel(string vlabel)
{
	this->vlabel = vlabel;
}

void Graph::setHLabel(string hlabel)
{
	this->hlabel = hlabel;
}

void Graph::setPlottingChar(char plotting_char)
{
	this->plotting_char = plotting_char;
}

string Graph::getTitle()
{
	return title;
}

string Graph::getVLabel()
{
	return vlabel;
}

string Graph::getHLabel()
{
	return hlabel;
}

char Graph::getPlottingChar()
{
	return plotting_char;
}

void Graph::setData(float value, int row, int col)
{
	data.at(row).at(col) = value;
	updateColMaxMin(col, value);
}

void Graph::updateColMaxMin(int col, float value)
{
	if(value > col_max.at(col))
		col_max.at(col) = value;
	if(value < col_min.at(col))
		col_min.at(col) = value;
}

void Graph::addRecord(vector<float>& record)
{
	incrementRows();
	for(unsigned int i = 0; i < num_cols; i++)
		data.at(data.length() - 1).at(i) = record.at(i);
}

void Graph::incrementRows()
{
	data.resize(data.length() + 1);
	data.at(data.length() - 1).resize(num_cols);
	num_rows++;
}
