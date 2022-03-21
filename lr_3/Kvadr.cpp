#include <iostream>
#include <fstream>
#include <cmath>
#include "Kvadr.h"
#include "Uravnenie.h"

using namespace std;

int Quadr::count = 0;

Quadr::Quadr() :a(1.0), b(0.0), c(0.0), y(0.0)
{
	++count;

	int c;
	string initfile_quadr = "data_quadr.txt";
	ifstream inFile;

	cout << "How do you want input data?" << endl;
	cout << "1 - Manually" << endl;
	cout << "2 - From file" << endl;
	cout << "0 - Exit" << endl;
	cout << "--> ";
	cin >> c;

	switch (c)
	{
	case 1:
		system("cls");
		cout << "Input coeff for quadration equation (a, b, c, y): ";
		cin >> a >> b >> this->c >> y;
		break;
	case 2:
		system("cls");
		inFile.open(initfile_quadr);
		if (!inFile)
		{
			cout << "Error opening data_quadr.txt!" << endl;
			exit(1);
		}
		cout << "Data is inputted like: quadration" << endl;
		inFile >> a >> b >> this->c >> y;
		cout << "Data was inputted!" << endl;
		inFile.close();
		break;
	case 0:
		exit(0);
		break;
	default:
		break;
	}
}

Quadr::Quadr(double m_a, double m_b, double m_c, double m_y)
{
	a = m_a;
	b = m_b;
	c = m_c;
	y = m_y;
	++count;
}

Quadr::Quadr(const Quadr& copy_kvadr)
{
	a = copy_kvadr.a;
	b = copy_kvadr.b;
	c = copy_kvadr.c;
	y = copy_kvadr.y;
	++count;
}

void Quadr::Root()
{
	ofstream outFile;
	string outfile = "result_quadr.txt";
	double x1, x2, D, sqrtD;
	c = c - y;
	D = pow(b, 2) - 4 * a * c;
	if (D < 0)
	{
		cout << "The quadration equation has no real roots due to negative discriminant" << endl;
		return;
	}

	if (D == 0)
	{
		x1 = (0 - b) / (2 * a);
		cout << "The quadration equation has one real root: x1 = " << x1 << endl;
		outFile.open(outfile, ios::app);
		if (!outFile)
		{
			cout << "Error openning file!" << endl;
			exit(1);
		}
		outFile << x1 << endl;
		outFile.close();
		return;
	}

	if (D > 0)
	{
		sqrtD = sqrt(D);
		x1 = ((0 - b) + sqrtD) / (2 * a);
		x2 = ((0 - b) - sqrtD) / (2 * a);
		cout << "The quadration equation has two real roots:" << endl;
		cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		outFile.open(outfile, ios::app);
		if (!outFile)
		{
			cout << "Error openning file!" << endl;
			exit(1);
		}
		outFile << x1 << "\n" << x2 << endl;
		outFile.close();
		return;
	}
}

void Quadr::set_coeff(double a, double b, double c, double y)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->y = y;
}

int Quadr::get_count()
{
	return count;
}

void Quadr::saving_to_file()
{
	ofstream outFile;
	string initfile_quadr = "data_quadr.txt";
	int c;

	cout << "Do you want to rewrite coeffs for kvadr?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;
	cin >> c;

	if (c == 1)
	{
		cout << "Input new data (with space): ";
		outFile.open(initfile_quadr);
		if (!outFile)
		{
			cout << "Error openning file!" << endl;
			exit(1);
		}
		cin >> a >> b >> this->c >> y;
		outFile << a << "\n" << b << "\n" << this->c << "\n" << y;
		cout << "The data was saved in data_quadr.txt!" << endl;
		outFile.close();
	}

	if (c == 2)
	{
		return;
	}
}