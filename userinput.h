#ifndef USERINPUT_H
#define USERINPUT_H

// Module which handles gathering interactive input from the user.

#include <iostream>
#include <string>

using namespace std;

namespace userinput
{
	// Gets the number of columns from the user.
	int getColumns();
	
	// Gets the number of rows from the user.
	int getRows();
	
	// Gets the title of the graph from the user.
	string getTitle();
	
	// Gets the label for the vertical axis from the user.
	string getVLabel();
	
	// Gets the label for the horizontal axis from the user.
	string getHLabel();
	
	// Gets a character to use for plotting.
	char getPlottingChar();
}

#endif
