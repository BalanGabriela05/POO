#include "Class.h"
#include <string.h>
#include <stdio.h>

void Class::setMath(float input)
{
	this->math = input;
}
float Class::getMath()
{
	return this->math;
}
void Class::setEnglish(float input)
{
	this->english = input;
}
float Class::getEnglish()
{
	return this->english;
}
void Class::setHistory(float input)
{
	this->history = input;
}
float Class::getHistory()
{
	return this->history;
}
void Class::setName(char name[20]) 
{
	strcpy_s(this->name, 20, name);
}

char* Class::getName()
{
	return this->name;
}
float Class::Funavarage()
{
	this->avarage = (this->math + this->english + this->history) / 3;
	return this->avarage;
} 