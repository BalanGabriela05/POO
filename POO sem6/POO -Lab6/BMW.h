#pragma once
#include "Car.h"
#include "Weather.h"

class BMW final : public Car
{
public:
	BMW();
	void printName();
	const float speedBasedOnWeather(Weather);
};

