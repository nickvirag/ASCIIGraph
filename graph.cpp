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
