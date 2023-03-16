#include "NumberList.h"
#include <string.h>
#include <stdio.h>

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (count < 10) {
		this->numbers[count] = x;
		this->count++;
		return true;
	}
	else return false;

}

void NumberList::Sort()
{
	for (int i = 0; i < this->count-1;i++)
	{
		for (int j = i + 1; j < this->count; j++)
		{
			if (this->numbers[i] > this->numbers[j])
			{
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
		}
	}
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d ", this->numbers[i]);
}