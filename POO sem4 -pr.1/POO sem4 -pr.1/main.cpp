#include <iostream>
#include <string.h>
#include "Sort.h"

using namespace std;

int main()
{

	cout << "Constructor 1 : " << endl;
	Sort s1(10, 0, 100);
	s1.Print();
	s1.InsertSort();
	s1.Print();
	cout << endl;

	cout << "Constructor 2 : " << endl;
	Sort s2 = { 3, 1, 5, 4, 2 };
	s2.Print();
	s2.BubbleSort(false);
	s2.Print();
	cout << endl;
#if 1
	cout << "Constructor 3 : " << endl;
	int n, v[] = { 2, 3, 1, 5, 4 };
	n = 5;
	Sort s3(v, 5);
	s3.Print();
	s3.BubbleSort(false);
	s3.Print();
	cout << endl;
#endif

	cout << "Constructor 4 : " << endl;
	Sort s4(5, 3, 1, 5, 4, 2);
	s4.Print();
	s4.InsertSort(false);
	s4.Print();
	cout << endl;

	cout << "Constuctor 5 : " << endl;
	// -> imi afiseaza random un 0 la final <- this->vector este initializat cu 0, altfel imi afisa o parte din memoria neinitializata
	char v_char[] = "3,1,2,5,4";
	Sort s5(v_char);
	s5.Print();
	s5.QuickSort(false);
	s5.Print();


	return 0;
}