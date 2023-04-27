#pragma once
#include "Car.h"
#include "Weather.h"

class RangeRover final : public Car
{
public:
	RangeRover();
	void printName();
	const float speedBasedOnWeather(Weather);
};

