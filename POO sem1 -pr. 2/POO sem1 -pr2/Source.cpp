#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
bool isPrime(int n)

{
	if (n == 0 || n == 1)
		return false;
	for (int tr = 2; tr <= n / 2; tr++)
		if ((n % tr) == 0)
			return false;

	return true;
}
int convert_caracter(const char* cuvant)
{
	double x;

	switch ((int)cuvant) {
	case 48:
		x = 0;
		break;

	case 49:
		x = 1;
		break;
	case 50:
		x = 2;
		break;
	case 51:
		x = 3;
		break;
	case 52:
		x = 4;
		break;
	case 53:
		x = 5;
		break;
	case 54:
		x = 6;
		break;
	case 55:
		x = 7;
		break;
	case 56:
		x = 8;
		break;
	case 57:
		x = 9;
		break;

	default:
		cout << "Input ul nu este un numar \n";
		x = -1;
	}
	return x;
}
int convert(char cuvant[])
{
	double x, nr = 0, lungime = strlen(cuvant);
	const char* a;
	for (int i = 0; i < strlen(cuvant); i++)
	{
		x = convert_caracter((const char*)cuvant[i]);
		cout << "x= " << x << "\n";
		if (x == -1)
			return -1;
		nr += pow(10, lungime - 1) * x;
		lungime--;
	}
	cout << "nr= " << nr << " \n";
	return nr;
}
int main()
{
	
	FILE* fp;
	if (fopen_s(&fp, "int.txt", "r") != 0)
	{
		printf("Eroare.Nu am putut deschide fisierul \n");
	}
	else
	{
		printf("Am deschis fisierul \n");
		char myString[201];
		double a = 0;
		double suma = 0;
		while (fgets(myString, 200, fp))
		{
			myString[strlen(myString) - 1] = '\0'; //scapam de new line ul in plus care aparea la afisare
			printf("Am citit din fisier: %s \n", myString);
			a = convert(myString);
			if (a != -1)
				suma += a;
		}
		cout << "Suma este: " << suma;
	}
	return 0;
}