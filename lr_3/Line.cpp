#include <iostream>
#include <fstream>
#include <cmath>
#include "Line.h"
#include "Uravnenie.h"

using namespace std;

int Linear::count = 0;

Linear::Linear() : a(1.0), b(0.0), y(0.0)
{
	++count;

	int c;
	ifstream inFile;
	string initfile_linear = "data_linear.txt";

	cout << "How do you want input data?" << endl;
	cout << "1 - Manually" << endl;
	cout << "2 - From file" << endl;
	cout << "0 - Exit" << endl;
	cout << "--> ";
	cin >> c;

	switch (c)
	{
	case 1: //Âðó÷íóþ
		system("cls");
		cout << "Input coeff for linear equation (a, b, y): ";
		cin >> a >> b >> y;
		break;
	case 2:
		system("cls");
		inFile.open(initfile_linear);
		if (!inFile)
		{
			cout << "Error opening data_linear.txt!" << endl;
			exit(1);
		}
		cout << "Data is inputted like: linear" << endl;
		inFile >> a >> b >> y;
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

Linear::Linear(float m_a, float m_b, float m_y)
{
	a = m_a;
	b = m_b;
	y = m_y;
	++count;

}
Linear::Linear(const Linear& copy_line)
{
	a = copy_line.a;
	b = copy_line.b;
	y = copy_line.y;
	++count;
}

void Linear::Root()
{
	string outfile = "result_linear.txt";
	ofstream outFile;
	float x = (y - b) / a;
	cout << "The root of linear equation is: x = " << x << endl;
	outFile.open(outfile, ios::app);
	if (!outFile)
	{
		cout << "Error openning file!" << endl;
		exit(1);
	}
	outFile << x << endl;
	outFile.close();

}

void Linear::set_coeff(float a, float b, float y)
{
	this->a = a;
	this->b = b;
	this->y = y;
}

int Linear::get_count()
{
	return count;
}

void Linear::saving_to_file()
{
	ofstream outFile;
	string initfile_linear = "data_linear.txt";
	int c;

	cout << "Do you want to rewrite coeffs foe linear?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;
	cin >> c;

	if (c == 1)
	{
		outFile.open(initfile_linear);
		if (!outFile)
		{
			cout << "Error openning file!" << endl;
			exit(1);
		}
		cout << "Input new data (with space): ";
		cout << "The first three coeff to linear and other four is for quadration" << endl;
		cin >> a >> b >> y;
		outFile << a << "\n" << b << "\n" << y;
		cout << "The data was saved in data_linear.txt!" << endl;
		outFile.close();
	}

	if (c == 2)
	{
		return;
	}
}