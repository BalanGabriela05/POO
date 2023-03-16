#include "GlobalClass.h"
#include <cstring>

int CMath(Class f1, Class f2)
{
	if (f1.getMath() > f2.getMath())
		return 1;
	else if (f1.getMath() == f2.getMath())
		return 0;
	else return -1;
}

int CEnglish(Class f1, Class f2)
{
	if (f1.getEnglish() > f2.getEnglish())
		return 1;
	else if (f1.getEnglish() == f2.getEnglish())
		return 0;
	else return -1;
}

int CHistory(Class f1, Class f2)
{
	if (f1.getHistory() > f2.getHistory())
		return 1;
	else if (f1.getHistory() == f2.getHistory())
		return 0;
	else return -1;
}

int CName(Class f1, Class f2)
{
	return strcmp(f1.getName(), f2.getName());
}

int Cavarage(Class f1, Class f2)
{
	if (f1.Funavarage() > f2.Funavarage())
		return 1;
	else if (f1.Funavarage() == f2.Funavarage())
		return 0;
	else return -1;
}