#pragma once
#include "Car.h"
#include "Weather.h"

class Seat final : public Car
{
public:
	Seat();
	void printName();
	const float speedBasedOnWeather(Weather);
};

