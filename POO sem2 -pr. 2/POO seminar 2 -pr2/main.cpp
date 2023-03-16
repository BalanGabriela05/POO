#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Class.h"
#include "GlobalClass.h"
using namespace std;
int main()
{
	Class f1;
	Class f2;

	f1.setMath(6.5);
	f1.setEnglish(7);
	f1.setHistory(9.2);
	f1.setName((char*)"Marian");
	f2.setMath(9);
	f2.setEnglish(8.3);
	f2.setHistory(6.1);
	f2.setName((char*)"Erica");

	printf("F1| nume: %s | nota mate: %f | nota engl: %f | nota istorie: %f | media : %f\n", f1.getName(), f1.getMath(), f1.getEnglish(), f1.getHistory() ,f1.Funavarage());
	printf("F2| nume: %s | nota mate: %f | nota engl: %f | nota istorie: %f | media : %f\n", f2.getName(), f2.getMath(), f2.getEnglish(), f2.getHistory(), f2.Funavarage());
	
	cout<<CMath(f1,f2)<<" ";

	cout << CEnglish(f1, f2) << " ";

	cout << CHistory(f1, f2) << " ";

	cout << CName(f1, f2) << " ";

	cout << Cavarage(f1, f2);
	return 0;
}