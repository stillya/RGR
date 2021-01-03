#pragma once

class Matrix {
private:
	int** matrix;
	int column;
	int row;
	
	void keyboardInputMatrix();
	void fileInputMatrix();
	void randomInputMatrix();
	int binarySearch(int a[], int item, int low, int high);
	int* insertionSortColumn(int* a);

public:
	Matrix(int column, int row);
	void inputMatrix(int statement);
	void printMatrix();
	int matrixEditor();
	void insertionSort();
	~Matrix();
};