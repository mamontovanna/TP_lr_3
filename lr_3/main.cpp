#include <iostream>
#include <string>
#include <fstream>
#include "Uravnenie.h"
#include "Line.h"
#include "Kvadr.h"

using namespace std;

int main()
{

	int c, count_equ = 0, exit_equ = 0, i = 0, N;

	cout << "Hello!" << endl;
	cout << "How many equations do you want?" << endl;
	cout << "--> ";
	cin >> N;

	Equation** equs = new Equation * [N];

	while (exit_equ != 1 && N > 0)
	{
		cout << "Do you want to work with..." << endl;
		cout << "1 - Linear equation" << endl;
		cout << "2 - Qudration equation" << endl;
		cout << "0 - Exit" << endl;
		cout << "--> ";
		cin >> c;

		if (c == 1)
		{
			equs[i] = new Linear;
			count_equ += equs[i]->get_count();
			equs[i]->Root();
			equs[i]->saving_to_file();
			i++;
			N--;
		}

		if (c == 2)
		{
			equs[i] = new Quadr;
			count_equ += equs[i]->get_count();
			equs[i]->Root();
			equs[i]->saving_to_file();
			i++;
			N--;
		}

		if (c == 0)
		{
			exit_equ = 1;
			cout << "You made " << count_equ << " equations" << endl;
		}
	}

	return 0;
}