#pragma once
#include "Car.h"
#include "Weather.h"

class Volvo final : public Car
{
public:
	Volvo();
	void printName();
	const float speedBasedOnWeather(Weather);
};

