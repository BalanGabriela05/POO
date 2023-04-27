#include "Circuit.h"
#include <iostream>
using namespace std;

Circuit::Circuit()
{
	number = 0;
	length = 0;
}

Circuit::~Circuit()
{
	for (int i = 0; i < number; i++)
		delete cars[i];
}

void Circuit::SetLength(const int a)
{
	length = a;
}

void Circuit::SetWeather(const Weather b)
{
	weather = b;
}

void Circuit::AddCar(Car* c)
{
	cars[number++] = c;
}

void Circuit::Race()
{
	for (int i = 0; i < number; i++)
		if (cars[i]->speedBasedOnWeather(weather) * (cars[i]->fuelCapacity / cars[i]->fuelConsumption) >= length)
			cars[i]->time = length / cars[i]->speedBasedOnWeather(weather);
		else
			cars[i]->time = -1; //marchez ca neterminat

}

void Circuit::ShowFinalRanks()
{
	Car* n;
	bool ok;
	do
	{
		ok = true;
		for (int i = 0; i < number - 1; i++)
			if (cars[i]->time > cars[i + 1]->time)
			{
				n = cars[i];
				cars[i] = cars[i + 1];
				cars[i + 1] = n;
				ok = false;
			}
	} while (!ok);
	cout << "Final ranks:" << endl;
	for (int i = 0; i < number; i++)
		if (cars[i]->time != -1)
		{
			cars[i]->printName();
			cout << cars[i]->time << " hours" << endl;

		}
	cout << endl;
}

void Circuit::ShowWhoDidNotFinish()
{
	bool ok = true;//toti au terminat
	for (int i = 0; i < number; i++)
		if (cars[i]->time == -1)
		{
			ok = false;
			break;
		}
	if (ok)
		cout << "Everyone finished!" << endl;
	else
	{
		cout << "Did not finish:" << endl;
		for (int i = 0; i < number; i++)
			if (cars[i]->time == -1)
			{
				cars[i]->printName();
				cout << endl;
			}
	}
	cout << endl;
}
