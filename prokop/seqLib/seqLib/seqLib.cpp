#include "pch.h"
#include "framework.h"
#include <fstream>

using namespace std;

double findLenght(string file)
{
	ifstream fin(file);
	double length = 0;
	int inclusion = 0;
	int localLenght = 0;
	char number = 0;

	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> number;
			number -= '0';

			if ((number % 2) == 0 && (number < 10)) {
				localLenght++;
			}
			else {
				inclusion++;
				length += localLenght;
				localLenght = 0;
			}
		}
		if (inclusion != 0) {
			length = length / inclusion;
			return length;
		}
		else {
			return 0;
		}
	}
	else
		return -1;
}