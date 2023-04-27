#include "RangeRover.h"
#include "Weather.h"
#include <iostream>


RangeRover::RangeRover()
{
	fuelCapacity = 40;
	fuelConsumption = 7;
	averageSpeed[Rain] = 60;
	averageSpeed[Sunny] = 75;
	averageSpeed[Storm] = 40;

}

void RangeRover::printName()
{
	std::cout << "Range Rover:";
}

const float RangeRover::speedBasedOnWeather(Weather w)
{
	return averageSpeed[w];
}
