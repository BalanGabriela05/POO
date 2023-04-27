#include "BMW.h"
#include "Weather.h"
#include <iostream>


BMW::BMW()
{
	fuelCapacity = 100;
	fuelConsumption = 15;
	averageSpeed[Rain] = 50;
	averageSpeed[Sunny] = 115;
	averageSpeed[Storm] = 40;

}

void BMW::printName()
{
	std::cout << "BMW:";
}

const float BMW::speedBasedOnWeather(Weather w)
{
	return averageSpeed[w];
}
