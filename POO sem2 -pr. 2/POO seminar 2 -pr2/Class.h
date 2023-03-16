#pragma once
class Class
{
private:
	float math, english, history;
	char name[20];
	float avarage;

public:
	void setMath(float input);
	float getMath();

	void setEnglish(float input);
	float getEnglish();

	void setHistory(float input);
	float getHistory();

	void setName(char* name);
	char* getName();

	float Funavarage();
};

