#include "Seat.h"
#include "Weather.h"
#include <iostream>


Seat::Seat()
{
	fuelCapacity = 60;
	fuelConsumption = 10;
	averageSpeed[Rain] = 55;
	averageSpeed[Sunny] = 95;
	averageSpeed[Storm] = 40;

}

void Seat::printName()
{
	std::cout << "Seat:";
}

const float Seat::speedBasedOnWeather(Weather w)
{
	return averageSpeed[w];
}
