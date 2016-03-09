#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <conio.h>
#include <cmath>
#include <iomanip>

using namespace std;

double CalculationDiscriminant(double const & a, double const & b, double const & c)
{
	return pow(b, 2) - (4 * a * c);
}

double CalculationRoot(double const & D, double const & a, double const & b, int const & sign)
{
	if (D == 0)
	{
		return -b / (2 * a);
	}
	else
	{
		return (-b + (sqrt(D) * sign)) / (2 * a);
	}
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "You have entered an false number of arguments!\nInput Example: solve.exe A B C" << endl;
		return 1;
	}
	else if (atof(argv[1]) == 0)
	{
		cout << "Parameter 'A' should not be set to 0." << endl;
		return 1;
	}
	else
	{
		double a = atof(argv[1]);
		double b = atof(argv[2]);
		double c = atof(argv[3]);
		double D;
		D = CalculationDiscriminant(a, b, c);
		if (D < 0)
		{
			cout << "There is no real root." << endl;
		}
		else
		{
			cout << setprecision(4) << CalculationRoot(D, a, b, 1) << endl;
			cout << setprecision(4) << CalculationRoot(D, a, b, -1) << endl;
		}
	}
	return 0;
}

