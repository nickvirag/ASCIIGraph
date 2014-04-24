#include "userinput.h"

using namespace std;

int userinput::getColumns()
{
	int columns;
	cout << "Please enter the number of columns in your data set: ";
	cin >> columns;
	return columns;
}

int userinput::getRows()
{
	int rows;
	cout << "Please enter the number of rows in your data set: ";
	cin >> rows;
	return rows;
}

string userinput::getTitle()
{
	string title;
	cout << "Please enter the title for your graph: ";
	getline(cin, title);
	return title;
}

string userinput::getVLabel()
{
	string label;
	cout << "Please enter the label for your vertical axis: ";
	getline(cin, label);
	return label;
}

string userinput::getHLabel()
{
	string label;
	cout << "Please enter the label for your horizontal axis: ";
	getline(cin, label);
	return label;
}
