#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "matrix.h"

int main() {

	int choose;
	Matrix* matrix = nullptr;

	while (true) {

		std::cout << "What do you want to do?" << std::endl << "1.Create Matrix   |    2.Print Matrix   |   3.Edit Matrix   |    4.Sort Matrix   |   5.Exit" << std::endl;
		std::cin >> choose;
	//	system("cls");
		switch (choose)
		{
		case 1:
			if (matrix != nullptr) {
				delete matrix;
			}
			int column, row;
			std::cout << std::endl << "Input size of matrix" << std::endl << "col row: ";
			std::cin >> column >> row;
			matrix = new Matrix(column, row);
			std::cout << std::endl << "What input method do you prefer?" << std::endl << "1.Keyboard  |  2.File  |  3.Random" << std::endl;
			int ch;
			std::cin >> ch;
			std::cout << std::endl << "Are you sure?" << std::endl << "1. Yes  |  2.No" << std::endl;
			int pr;
			std::cin >> pr;
			if (pr == 1)
				matrix->inputMatrix(ch);
			else
				break;
			break;
		case 2:
			if (matrix != nullptr)
				matrix->printMatrix();
			else
				std::cout << std::endl << "Matrix is not created" << std::endl;
			break;
		case 3:
			if (matrix != nullptr) {
				std::cout << std::endl << "Are you sure?" << std::endl << "1. Yes  |  2.No" << std::endl;
				int ch;
				std::cin >> ch;
				if (ch == 1)
					matrix->matrixEditor();
				else
					break;
			}
			else
				std::cout << std::endl << "Matrix is not created" << std::endl;
			break;
		case 4:
			std::cout << std::endl << "Are you sure?" << std::endl << "1. Yes  |  2.No" << std::endl;
			int ch_1;
			std::cin >> ch_1;
			if (ch_1 == 1)
				matrix->insertionSort();
			else
				break;
			break;
		case 5: 
			return 0;
		default:
			std::cout << std::endl << "Wrong options" << std::endl;
			break;
		}

	}
}