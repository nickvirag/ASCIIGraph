#include "graph.h"

Graph::Graph()
{
	plotting_char = '*';
	width = 40;
	height = 10;
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

string Graph::getGraph()
{
	int displayArray[ height ][ width ];
	for( int y = 0; y < height; y ++ ){
		for( int x = 0; x < width; x ++ ){
			displayArray[ y ][ x ] = 0;
		}
	}
	for( int z = 0, x = 0; x < data.size( ); z ++ ){
		int locX = ( data.at( z ).x * width  ) / x_max;
		int locY = ( data.at( z ).y * height ) / y_max;
		displayArray[ locY ][ locX ] = 1;
		x ++;
	}
	string rval = "   " + title + "\n   ";
	for( int x = 0; x < (width + 2); x ++ ){
		rval += "+";
	}
	rval += "\n";
	for( int y = height - 1, z = 0; y >= 0; y -- ){
		if( z < vlabel.length( ) ){
			stringstream tstr;
			tstr << vlabel[ z ];
			rval += " " + tstr.str( ) + " +";
			z ++;
		}else{
			rval += "   +";
		}
		for( int x = 0; x < width; x ++ ){			
			if( displayArray[ y ][ x ] == 0 ){
				rval += " ";
			}else{
				rval += plotting_char;
			}
		}
		rval += "+\n";
	}
	rval += "   ";
	for( int x = 0; x < (width + 2); x ++ ){
		rval += "+";
	}
	rval += "\n   " + hlabel + "\n";
	return rval;
}

void Graph::setConsoleDimensions( int w, int h ){
	width = w;
	height = h;
}