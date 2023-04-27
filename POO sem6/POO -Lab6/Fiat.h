#pragma once
#include "Car.h"
#include "Weather.h"

class Fiat final : public Car
{
public:
	Fiat();
	void printName();
	const float speedBasedOnWeather(Weather);
};

