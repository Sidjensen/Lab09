// Lab09.cpp : Defines the entry point for the console application.
// Sidney Jensen
// 12/3/18

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
	fstream myfile;
	string filename, data;
	map<string, int> myMap;
	cout << "Enter the name of the file: ";
	cin >> filename;
	myfile.open(filename);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> data;
			++myMap[data];
		}
	}
	myfile.close();

	ofstream output("output.txt");

	for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
		for (int index = 0; index < it->second; index++)
		{
			output << it->first;
		}
	}
	output.close();

    return 0;
}

//string readFrom(string file)
//{
//	string output;
//	ifstream myfile;
//	myfile.open(file);
//	if (myfile.is_open())
//	{
//		while (!myfile.eof())
//		{
//			myfile >> output;
//		}
//	}
//	myfile.close();
//	return output;
//}
//
//void writeTo(string file, string input)
//{
//	ofstream myfile;
//	myfile.open(file);
//	if (myfile.is_open())
//	{
//		myfile << input;
//	}
//	myfile.close();
//}