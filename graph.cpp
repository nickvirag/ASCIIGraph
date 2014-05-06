#include "graph.h"

Graph::Graph()
{
	plotting_char = '*';
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

void Graph::addData(float x, float y)
{
	incrementRows();
	data.at(data.size() - 1).x = x;
	data.at(data.size() - 1).y = y;
	updateMaxMin(x, y);
}

void Graph::addData(Pair record)
{
	addData(record.x, record.y);
}

void Graph::updateMaxMin(float x, float y)
{
	x_max = x > x_max ? x : x_max;
	x_min = x < x_min ? x : x_min;
	y_max = y > y_max ? y : y_max;
	y_min = x < y_min ? y : y_min;
}

void Graph::incrementRows()
{
	data.resize(data.size() + 1);
}
