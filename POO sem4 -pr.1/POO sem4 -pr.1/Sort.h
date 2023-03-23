#pragma once
#include <initializer_list>

using namespace std;

class Sort
{
	int n;
	int* vector;
public:
	Sort(int n, int min, int max);
	Sort(initializer_list<int> vector);
	Sort(int vector[100], int n);
	Sort(int count, ...);// use va_args for this
	Sort(char* vector);
	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int GetElemetsCount();
	int GetElementsFromIndex(int index);
};