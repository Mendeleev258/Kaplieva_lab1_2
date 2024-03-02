// КИМ 12
// Дана целочисленная квадратная матрица.
// 1) Проверить, есть ли в матрице хотя бы два симметричных столбца, если есть, вывести их номера.
// 2) Переместить вниз строки, содержащие числа, оканчивающиеся на заданную цифру, 
// остальные строчки заполнить нулями. Среди оставшихся строк, сохранить исходный взаимный порядок.

#include <iostream>
#include <iomanip>
#include <fstream>

const int size = 4;

// static matrix
void fillarr(int* arr, int a, int b);
void fillarr(int* arr, std::istream& stream);
void fillmatrix(int matr[][size], int a, int b);
void fillmatrix(int matr[][size], std::istream& stream);
void printarr(int* arr);
void printmatrix(int matr[][size]);

// dynamic matrix
int** memory_allocation(int size_d);
void free_memory(int**& matr, int size_d);
void fillarr(int* arr, int a, int b, int size_d);
void fillarr(int* arr, std::istream& stream, int size_d);
void fillmatrix(int** matr, int a, int b, int size_d);
void fillmatrix(int** matr, std::istream& stream, int size_d);
void printarr(int* arr, int size_d);
void printmatrix(int** matr, int size_d);



// task 1
void transposition(int matr[][size]);

int main()
{
	/*int matrix[size][size];
	std::ifstream file("file.txt");
	fillmatrix(matrix, std::cin);
	printmatrix(matrix);
	std::cout << "transposition\n";
	transposition(matrix);
	printmatrix(matrix);*/
	
	std::ifstream file("file.txt");
	int size_d = 3;
	int** matrix = memory_allocation(size_d);
	fillmatrix(matrix, 10, 100, size_d);
	printmatrix(matrix, size_d);
}



// static matrix
void fillarr(int* arr, int a, int b)
{
	for (int i{}; i < size; ++i)
		arr[i] = a + rand() % (b - a);
}

void fillarr(int* arr, std::istream& stream)
{
	for (int i{}; i < size; ++i)
		stream >> arr[i];
}

void fillmatrix(int matr[][size], int a, int b)
{
	for (int i{}; i < size; ++i)
		fillarr(matr[i], a, b);
}

void fillmatrix(int matr[][size], std::istream& stream)
{
	for (int i{}; i < size; ++i)
		fillarr(matr[i], stream);
}

void printarr(int* arr)
{
	for (int i{}; i < size; ++i)
		std::cout << std::setw(4) << arr[i];
	std::cout << '\n';
}

void printmatrix(int matr[][size])
{
	for (int i{}; i < size; ++i)
		printarr(matr[i]);
}

// dynamic matrix
int** memory_allocation(int size_d)
{
	int** matr = new int* [size_d];
	for (int i{}; i < size_d; ++i)
		matr[i] = new int[size_d];
	return matr;
}

void free_memory(int**& matr, int size_d)
{
	for (int i{}; i < size_d; ++i)
		delete[]matr[i];
	delete[]matr;
}

void fillarr(int* arr, int a, int b, int size_d)
{
	for (int i{}; i < size_d; ++i)
		arr[i] = a + rand() % (b - a);
}

void fillarr(int* arr, std::istream& stream, int size_d)
{
	for (int i{}; i < size_d; ++i)
		stream >> arr[i];
}

void printarr(int* arr, int size_d)
{
	for (int i{}; i < size_d; ++i)
		std::cout << std::setw(4) << arr[i];
	std::cout << '\n';
}

void fillmatrix(int** matr, int a, int b, int size_d)
{
	for (int i{}; i < size_d; ++i)
		fillarr(matr[i], a, b, size_d);
}

void fillmatrix(int** matr, std::istream& stream, int size_d)
{
	for (int i{}; i < size_d; ++i)
		fillarr(matr[i], stream, size_d);
}

void printmatrix(int** matr, int size_d)
{
	for (int i{}; i < size_d; ++i)
		printarr(matr[i], size_d);
}

// task 1
void transposition(int matr[][size])
{
	for (int i{}; i < size - 1; ++i)
		for (int j = i + 1; j < size; ++j)
			std::swap(matr[i][j], matr[j][i]);
}