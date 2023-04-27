#include "Volvo.h"
#include "Weather.h"
#include <iostream>

Volvo::Volvo()
{
	fuelCapacity = 50;
	fuelConsumption = 5;
	averageSpeed[Rain] = 50;
	averageSpeed[Sunny] = 80;
	averageSpeed[Storm] = 30;

}

void Volvo::printName()
{
	std::cout << "Volvo:";
}

const float Volvo::speedBasedOnWeather(Weather w)
{
	return averageSpeed[w];
}
