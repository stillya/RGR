#include <fstream>
#include <iostream>

using namespace std;

double func();
double func1();

int main()
{

	double result = func1();
	cout << result;
}


double func()
{

	ifstream fis("text.txt");
	double result = 0;
	int temp;
	int num = 0;
	int size = 0;

	if (fis.is_open()) {

		while (!fis.eof()) {

			temp = fis.get() - 48;

			while (temp == 9) {
				num++;
				while ((temp = fis.get() - 48) != 9 && !fis.eof()) {
					num++;
				}
				result += num;
				num = 0;
				size++;
			}

		}
		return result / size;
	}

}

double func1() {

	ifstream fis("test.txt");
	double result = 0;
	int temp;
	int num = 0;
	int size = 0;


	if (fis.is_open()) {

		while (!fis.eof()) {

			temp = fis.get() - 48;

			if (temp % 2 == 0) {
				num++;
				while ((temp = fis.get() - 48) % 2 == 0) {
					num++;
				}
				result += num;
				size++;
				num = 0;
			}

		}
	}
	return result / size;
}