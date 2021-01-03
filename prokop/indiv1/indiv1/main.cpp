#include <fstream>
#include <iostream>
#include "seqLib.h"

using namespace std;

int test(char *argv[]);

int main(int argc, char* argv[])
{
	int result = test(argv);
	cout << "Result: " << result; 
}

int test(char* argv[])
{
	string test = argv[0];
	ofstream result(test);
	string name; 

	cin >> name; 

	double lenght = findLenght(name);
	
	if (lenght == -1) {
		cout << "Input file doesn't exist";
	}
	else {
		if (result.is_open())
			result << lenght;
		else
			cout << "Output file doesn't exits";
	}
	
	return lenght;
}
