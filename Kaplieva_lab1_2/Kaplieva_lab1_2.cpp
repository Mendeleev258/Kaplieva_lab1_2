// КИМ 12
// Дана целочисленная квадратная матрица.
// 1) Проверить, есть ли в матрице хотя бы два симметричных столбца, если есть, вывести их номера.
// 2) Переместить вниз строки, содержащие числа, оканчивающиеся на заданную цифру, 
// остальные строчки заполнить нулями. Среди оставшихся строк, сохранить исходный взаимный порядок.

#include <iostream>
#include <iomanip>

const int size = 5;

// static matrix
void fillarr(int* arr, int a, int b);
void fillmatrix(int matr[][size], int a, int b);
void printarr(int* arr);
void printmatrix(int matr[][size]);

// dynamic matrix
int** memory_allocation(int size);
void free_memory(int**& matr);
void fillmatrix(int** matr, int a, int b);
void printmatrix(int** matr);

int main()
{
	int** d_matrix = memory_allocation(size);
	fillmatrix(d_matrix, 0, 20);
	printmatrix(d_matrix);
	free_memory(d_matrix);
}



// static matrix
void fillarr(int* arr, int a, int b)
{
	for (int i{}; i < size; ++i)
		arr[i] = a + rand() % (b - a);
}

void fillmatrix(int matr[][size], int a, int b)
{
	for (int i{}; i < size; ++i)
		fillarr(matr[i], a, b);
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
int** memory_allocation(int size)
{
	int** matr = new int* [size];
	for (int i{}; i < size; ++i)
		matr[i] = new int[size];
	return matr;
}

void free_memory(int**& matr)
{
	for (int i{}; i < size; ++i)
		delete[]matr[i];
	delete[]matr;
}

void fillmatrix(int** matr, int a, int b)
{
	for (int i{}; i < size; ++i)
		fillarr(matr[i], a, b);
}

void printmatrix(int** matr)
{
	for (int i{}; i < size; ++i)
		printarr(matr[i]);
}
