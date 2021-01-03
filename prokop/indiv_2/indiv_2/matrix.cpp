#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "matrix.h"
#include <map>

void Matrix::keyboardInputMatrix() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
		{
			std::cout << "Enter element " << "[" << i << "][" << j << "]  ";
			std::cin >> matrix[i][j];
		}
}

void Matrix::fileInputMatrix() {
	std::string file;
	std::cout << std::endl << "What is file name?" << std::endl;
	std::cin >> file;

	std::ifstream fin(file);

	if (fin.is_open()) {
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				fin >> matrix[i][j];
	}
	else
		std::cout << std::endl << "File doesn't open" << std::endl;
}

void Matrix::randomInputMatrix() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = rand();
}

int Matrix::binarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}

Matrix::Matrix(int column, int row) {
	this->column = column;
	this->row = row;

	matrix = new int* [row];
	for (int i = 0; i < row; ++i)
		matrix[i] = new int[column];
}

void Matrix::inputMatrix(int statement) {
	switch (statement)
	{
	case 1:
		keyboardInputMatrix();
		break;
	case 2:
		fileInputMatrix();
		break;
	case 3:
		randomInputMatrix();
		break;
	default:
		std::cout << "We haven't this method" << std::endl;
		break;
	}
}


void Matrix::printMatrix() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

int Matrix::matrixEditor() {
	if (matrix != nullptr) {
		int x_position = 0;
		int y_position = 0;

		std::cout << std::endl << "Matrix editor" << "\n\n" << "Optionals:" << std::endl << "Right: move cursor right" << std::endl << "Left: move cursor left" << std::endl << "Down: exit from editor" << std::endl;

		while (true) // Key waiting loop
		{
			if (_kbhit())
			{
				switch (_getch()) // Check key
				{
				case 80:
					return 1;
					break;
				case 75:
					if (x_position >= 0 && y_position > 0) {
						system("cls");
						std::cout << "Current symbol: " << matrix[y_position - 1][x_position] << "\n\n\n\n\n\n";
						std::cout << "Optionals:" << std::endl << "Right: move cursor right" << std::endl << "Left: move cursor left" << std::endl << "Down: exit from editor" << std::endl;
						std::cout << "Input new symbol: ";
						std::cin >> matrix[y_position - 1][x_position];
						if (x_position == 0) {
							y_position--;
							if (y_position == 0)
								break;
							x_position = row - 1;
						}
						else {
							x_position--;
						}
					}
					else
						std::cout << "Out of border";
					break;
				case 77:
					if (x_position < row && y_position < column) {
						system("cls");
						std::cout << "Current symbol: " << matrix[y_position][x_position] << "\n\n\n\n\n\n";
						std::cout << "Optionals:" << std::endl << "Right: move cursor right" << std::endl << "Left: move cursor left" << std::endl << "Down: exit from editor" << std::endl;
						std::cout << "Input new symbol: ";
						std::cin >> matrix[y_position][x_position];
						if (x_position == row - 1) {
							y_position++;
							if (y_position == row)
								break;
							x_position = 0;
						}
						else {
							x_position++;
						}
					}
					else
						std::cout << "Out of border";
					break;
				default:
					std::cout << "Wrong key" << std::endl;
				}

			}
		}
	}
	else
		return -1;
}

int* Matrix::insertionSortColumn(int* a) {
	int i, loc, j, k, selected;

	for (i = 1; i < this->column; i++)
	{
		j = i - 1;
		selected = a[i];
		loc = binarySearch(a, selected, 0, j);
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
	
	return a;
}

void Matrix::insertionSort() {
	int* a = new int[this->column];
	int** fakeMatrix;
	std::map<int, int> position;
	int sum = 0;

	fakeMatrix = new int* [row];
	for (int i = 0; i < row; ++i)
		fakeMatrix[i] = new int[column];

	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->column; j++)
			fakeMatrix[i][j] = this->matrix[i][j];

	for (int i = 0; i < this->column; i++) { // collect sum of columns
		for (int j = 0; j < this->row; j++) {
			sum += this->matrix[j][i];
		}
		a[i] = sum;
		position[sum] = i;
		sum = 0;
	}

	a = insertionSortColumn(a); // sort sum of columns with their positions in array

	for (int i = 0; i < this->column; i++) {
		int value = a[i];
		int pos = position[value];
		
		for (int j = 0; j < this->row; j++) {
			matrix[j][i] = fakeMatrix[j][pos]; // Swap columns on position according to them positions
		}
	}

	for (int i = 0; i < this->row; i++) {
		delete[] fakeMatrix[i];
	}
	delete[] fakeMatrix;
}

Matrix::~Matrix() {
	for (int i = 0; i < this->row; i++) {
		delete[] this->matrix[i];
	}
	delete[] this->matrix;
}

