#include "Fiat.h"
#include "Weather.h"
#include <iostream>


Fiat::Fiat()
{
	fuelCapacity = 55;
	fuelConsumption = 12;
	averageSpeed[Rain] = 55;
	averageSpeed[Sunny] = 100;
	averageSpeed[Storm] = 40;

}

void Fiat::printName()
{
	std::cout << "Fiat:";
}

const float Fiat::speedBasedOnWeather(Weather w)
{
	return averageSpeed[w];
}
