#include "pch.h"
#include <iostream>

void fill_arr(int* arr, short sz);
void get_order(const int* arr1, int* arr2, short sz);
void get_reorder(const int* arr1, int* arr2, short sz);
void show_arr(const int* arr, short sz);


int main()
{
	using namespace std;
	setlocale(0, "");
	cout << "Введите размер массива --> ";
	short Size;
	cin >> Size;
	int* ordered_arr = new int[Size];
	int* reordered_arr = new int[Size];
	reordered_arr[Size] = { 0 };
	int* disordered_arr = new int[Size];
	fill_arr(disordered_arr, Size);
	get_order(disordered_arr, ordered_arr, Size);
	get_reorder(ordered_arr, reordered_arr, Size);
	cout << "\nНеупорядоченный массив:\n";
	show_arr(disordered_arr, Size);
	cout << "Упорядоченные массив:\n";
	show_arr(ordered_arr, Size);
	cout << "Массив, упорядоченный в обратном порядке:\n";
	show_arr(reordered_arr, Size);

	return 0;
}

void fill_arr(int* arr, const short sz)
{
	using namespace std;
	setlocale(0, "");
	cout << "Введите значения элементов массива:\n";
	for (int i = 0; i < sz; i++)
	{
		cout << "[" << i << "] --> ";
		cin >> arr[i];
	}
}

void get_order(const int* arr1, int* arr2, const short sz)
{
	int hp;
	for (int i = 0; i < sz; i++)
	{
		arr2[i] = arr1[i];
	}
	for (int i = 1; i < sz; i++)
	{
		for (int j = i; j > 0 && arr2[j - 1] > arr2[j]; j--)
		{
			hp = arr2[j - 1];
			arr2[j - 1] = arr2[j];
			arr2[j] = hp;
		}
	}
}

void get_reorder(const int* arr1, int* arr2, short sz)
{
	int hp;
	int count = 0;
	for (int i = 0; i < sz; i++)
	{
		arr2[i] = arr1[i];
	}
	while (count != sz - 1)
	{
		for (int j = sz - 1; j > 0 && arr2[j] > arr2[j - 1]; j--)
		{
			hp = arr2[j - 1];
			arr2[j - 1] = arr2[j];
			arr2[j] = hp;
		}
		count++;
	}
}

void show_arr(const int* arr, short sz)
{
	for (int i = 0; i < sz; i++)
	{
		std::cout << "[" << i << "] --> " << arr[i] << "\n";
	}
}

