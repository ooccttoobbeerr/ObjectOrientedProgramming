#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

void CopyInputFileToOutputFile(istream & inputFile, ostream & outputFile)
{
	string str;
	while (getline(inputFile, str))
	{
		outputFile << str << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "You have entered an false number of arguments!\nInput Example: lab_1.exe input.txt output.txt" << endl;
		return 1;
	}
	else
	{
		ifstream inputFile(argv[1]);
		ofstream outputFile(argv[2]);
		if (inputFile.is_open() && outputFile.is_open())
		{
			CopyInputFileToOutputFile(inputFile, outputFile);
		}
		else
		{
			cout << "Error opening file!" << endl;
			return 1;
		}
		inputFile.close();
		outputFile.close();
	}
	return 0;
}