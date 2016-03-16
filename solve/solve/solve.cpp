#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <conio.h>
#include <cmath>
#include <iomanip>

using namespace std;

double CalculateDiscriminant(double const & a, double const & b, double const & c)
{
	return (b * b) - (4 * a * c);
}

double CalculateRoot(double const & D, double const & a, double const & b, int const & sign)
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

void PrintResult(double const &a, double const &b, double const &D)
{
		if (a == 0)
		{
			cout << "Parameter 'A' should not be set to 0." << endl;
		}
		else if (D < 0)
		{
			cout << "Discriminant is less than zero. There is no real root." << endl;
		}
		else
		{
			cout << fixed << setprecision(3) << CalculateRoot(D, a, b, 1) << endl;
			cout << fixed << setprecision(3) << CalculateRoot(D, a, b, -1) << endl;
		}
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "You have entered an false number of arguments!\nInput Example: solve.exe A B C" << endl;
		return 1;
	}
	else
	{
		double a = atof(argv[1]);
		double b = atof(argv[2]);
		double c = atof(argv[3]);
		double D;
		D = CalculateDiscriminant(a, b, c);
		PrintResult(a, b, D);
	}
	return 0;
}

