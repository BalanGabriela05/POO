#pragma once
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
class Circuit
{
	int length;
	Car* cars[100];
	int number;
	Weather weather;
public:
	Circuit();
	~Circuit();
	void SetLength(const int);
	void SetWeather(const Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

