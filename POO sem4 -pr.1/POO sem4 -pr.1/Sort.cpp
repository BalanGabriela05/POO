#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <string.h>
#include <initializer_list>
#include "Sort.h"
//#pragma warning(disable : 4996) -> nu mai trebuie sa folosesc strtok_s si strcpy_s daca pun asta

using namespace std;

Sort::Sort(int n, int min, int max)
{
	this->n = n;
	this->vector = new int[n];

	srand(time(nullptr));

	for (int i = 0; i < n; i++)
	{
		vector[i] = rand() % (max - min + 1) - min;
	}
}

Sort::Sort(initializer_list<int> list) // o lista cu elemente de tip int
{
	this->n = list.size();

	this->vector = new int[n];

	int i = 0;
	for (auto element : list) // fiecare element va lua valoarea elementului din lista asociat ; loop ul se va termina cand lista va fi parcursa toata
	{
		this->vector[i] = element;
		i++;
	}
}

Sort::Sort(int vector[100], int n)
{
	int x;

	this->n = n;
	this->vector = new int[n];

	for (int i = 0; i < n; i++)
	{
		this->vector[i] = vector[i];
	}
}

Sort::Sort(int n, ...)
{
	va_list args;

	this->n = n;
	this->vector = new int[n];

	va_start(args, n);

	for (int i = 0; i < n; i++)
	{
		vector[i] = va_arg(args, int);
	}

	va_end(args);
}

Sort::Sort(char* vector)
{
	char* p;
	int a, pr = 1, numar = 0, k = 0;

	char* copie = new char[strlen(vector) + 1];
	strcpy_s(copie, strlen(vector) + 1, vector);
	copie[strlen(vector)] = '\0';

	p = strtok_s(copie, ",", &copie);

	while (p)
	{
		k++;
		p = strtok_s(nullptr, ",", &copie);
	}

	this->n = k;
	this->vector = new int[k];
	k = 0;

	char* v = new char[strlen(vector) + 1];
	strcpy_s(v, strlen(vector) + 1, vector);
	v[strlen(vector)] = '\0';

	p = strtok_s(v, ",", &v);

	while (p)
	{
		for (int i = strlen(p) - 1; i >= 0; i--)
		{
			a = (int)p[i] - (int)'0';
			numar += pr * a;
			pr *= 10;
		}

		this->vector[k] = numar;
		k++;
		pr = 1;
		numar = 0;

		p = strtok_s(nullptr, ",\n", &v);
	}
	//cout << k << endl;
}

void Sort::InsertSort(bool ascendent)
{
	int key, space;

	for (int i = 1; i < n; i++)
	{
		key = vector[i];
		space = i;

		for (int j = space - 1; j >= 0; j--)
		{
			if (ascendent ? (vector[i] > key) : (vector[j] < key))
			{
				vector[j + 1] = vector[j];
				space = j;
				continue;
			}
			break;
		}
		vector[space] = key;
	}

}

int Partition(int* vector, int start, int end, bool ascendent)
{
	int pivot, pi;

	pivot = vector[end]; //prima data pivotul va fi ultimul element din vector
	pi = start; // <- indexul pivotului

	for (int i = start; i <= end - 1; i++)
	{
		if (ascendent ? vector[i] >= pivot : vector[i] <= pivot)
		{
			swap(vector[pi], vector[i]);
			pi++;
		}
	}
	swap(vector[pi], vector[end]);

	return pi;
}

void QuickSortRecursiv(int* vector, int start, int end, bool ascendent)
{
	int pi;

	if (start < end)
	{
		pi = Partition(vector, start, end, ascendent);
		QuickSortRecursiv(vector, start, pi - 1, ascendent);
		QuickSortRecursiv(vector, pi + 1, end, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortRecursiv(vector, 0, n - 1, ascendent);
}

void Print(int n, int* vector)
{
	for (int i = 0; i < n; i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}

void Sort::BubbleSort(bool ascendent)
{
	int ok;

	do
	{
		ok = 1;

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (ascendent ? (vector[i] > vector[j]) : (vector[i] < vector[j]))
				{
					swap(vector[i], vector[j]);
					ok = 0;
				}
			}
		}
	} while (!ok);
}

void Sort::Print()
{
	for (int i = 0; i < n; i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}

int Sort::GetElemetsCount()
{
	return n;
}

int Sort::GetElementsFromIndex(int index)
{
	//vector separat

	if (index >= 0 && index < n - 1)
	{
		for (int i = index; i < n; i++)
		{
			cout << this->vector[i] << " ";
		}
		cout << endl;
	}
	else if (index = n - 1) return this->vector[n - 1];
	else return -1;
}