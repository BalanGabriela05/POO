#include "Number.h"


int switchFromBaseBtoBase10(Number* n)
{
	int x = 0, power = 0;
	for (int i = n->size - 1; i >= 0; i--)
	{
		if (n->value[i] == 'F')
		{
			x = x + 15 * pow(n->base, power);
			power++;
		}
		else if (n->value[i] == 'E')
		{
			x = x + 14 * pow(n->base, power);
			power++;
		}
		else if (n->value[i] == 'D')
		{
			x = x + 13 * pow(n->base, power);
			power++;
		}
		else if (n->value[i] == 'C')
		{
			x = x + 12 * pow(n->base, power);
			power++;
		}
		else if (n->value[i] == 'B')
		{
			x = x + 11 * pow(n->base, power);
			power++;
		}
		else if (n->value[i] == 'A')
		{
			x = x + 10 * pow(n->base, power);
			power++;
		}
		else
		{
			x = x + (n->value[i] - '0') * pow(n->base, power);
			power++;
		}
	}
	return x;
}

void switchFromBase10toBaseB(Number* n, int rests, int* vector)
{
	for (int i = 0; i < rests; i++)
	{
		if (vector[i] == 10)
			n->value[i] = 'A';
		else if (vector[i] == 11)
			n->value[i] = 'B';
		else if (vector[i] == 12)
			n->value[i] = 'C';
		else if (vector[i] == 13)
			n->value[i] = 'D';
		else if (vector[i] == 14)
			n->value[i] = 'E';
		else if (vector[i] == 15)
			n->value[i] = 'F';
		else n->value[i] = vector[i] + '0';
	}
}

Number::Number(const char* value, int base)
{
	this->base = base;
	this->size = 0;
	int i = 0;

	while (value[i] != '\0')
	{
		this->size++;
		i++;
	}

	this->value = new char[this->size + 1];
	for (int i = 0; i < this->size; i++)
		this->value[i] = '\0';

	for (int i = 0; i < this->size; i++)
		this->value[i] = value[i];
	this->valueInteger = switchFromBaseBtoBase10(this);
}

Number::Number(int value)
{

	this->base = 10;
	this->valueInteger = value;
	int val = value, aux1 = val, digits = 0;


	while (aux1)
	{
		digits++;
		aux1 /= 10;
	}

	int* v1 = new int[digits];
	int* v2 = new int[digits];

	for (int i = 0; i < digits; i++)
	{
		v1[i] = 0;
		v2[i] = 0;
	}

	for (int i = 0; i < digits; i++)
	{
		v1[i] = val % 10;
		val /= 10;
	}
	for (int i = 0; i < digits; i++)
		v2[i] = v1[digits - i - 1];

	this->value = new char[digits + 1];
	this->value[digits] = '\0';
	switchFromBase10toBaseB(this, digits, v2);

	size = digits + 1;

	delete[] v1;
	delete[] v2;

}

Number::~Number()
{
	delete[] value;
}

Number::Number(const Number& n)
{
	size = n.size;
	base = n.base;
	valueInteger = n.valueInteger;
	value = new char[size];
	for (int i = 0; i < size; i++)
		value[i] = n.value[i];
}

Number::Number(Number&& n)
{
	size = n.size;
	base = n.base;
	valueInteger = n.valueInteger;
	value = n.value;
	n.value = nullptr;
}

int Number::GetBase()
{
	return this->base;
}

int Number::GetDigitsCount()
{
	return this->size;
}

Number Number::operator+(const Number& n)
{
	int val = valueInteger + n.valueInteger, aux1 = val, digits = 0, maxBase = base;

	if (base < n.base)
		maxBase = n.base;
	while (aux1)
	{
		digits++;
		aux1 /= 10;
	}

	char* string = new char[digits + 1];
	int* v = new int[digits];

	for (int i = 0; i < digits; i++)
	{
		v[i] = 0;
		string[i] = '\0';
	}

	for (int i = 0; i < digits; i++)
	{
		v[i] = val % 10;
		val /= 10;
	}

	for (int i = 0; i < digits; i++)
		string[i] = (char)(v[digits - i - 1] + '0');
	string[digits] = '\0';

	Number aux((const char*)string, 10);

	aux.SwitchBase(maxBase);

	delete[] v;
	delete[] string;

	aux.size--;
	return aux;
}

Number Number::operator-(const Number& n)
{
	int val = valueInteger - n.valueInteger, aux1 = val, digits = 0, maxBase = base;

	if (base < n.base)
		maxBase = n.base;

	while (aux1)
	{
		digits++;
		aux1 /= 10;
	}

	char* string = new char[digits + 1];
	int* v = new int[digits];

	for (int i = 0; i < digits; i++)
	{
		v[i] = 0;
		string[i] = '\0';
	}

	for (int i = 0; i < digits; i++)
	{
		v[i] = val % 10;
		val /= 10;
	}

	for (int i = 0; i < digits; i++)
		string[i] = (char)(v[digits - i - 1] + '0');
	string[digits] = '\0';

	Number aux((const char*)string, 10);

	aux.SwitchBase(maxBase);

	delete[] v;
	delete[] string;

	return aux;

}

Number& Number::operator=(const Number& n)
{
	size = n.size;
	base = n.base;
	valueInteger = n.valueInteger;
	for (int i = 0; i < n.size; i++)
		value[i] = n.value[i];
	return *this;
}

Number& Number::operator=(int n)
{
	base = 10;
	valueInteger = n;
	int val = n, aux1 = val, digits = 0, maxBase = base;


	while (aux1)
	{
		digits++;
		aux1 /= 10;
	}

	int* v1 = new int[digits];
	int* v2 = new int[digits];

	for (int i = 0; i < digits; i++)
	{
		v1[i] = 0;
		v2[i] = 0;
	}

	for (int i = 0; i < digits; i++)
	{
		v1[i] = val % 10;
		val /= 10;
	}
	for (int i = 0; i < digits; i++)
		v2[i] = v1[digits - i - 1];

	delete[] value;
	value = new char[digits + 1];
	value[digits] = '\0';
	switchFromBase10toBaseB(this, digits, v2);

	size = digits + 1;

	delete[] v1;
	delete[] v2;
	return *this;

}

Number& Number::operator=(const char* n)
{
	int strsize = 0, i = 0;
	while (n[i] != '\0')
	{
		strsize++;
		i++;
	}

	delete[] value;
	value = new char[strsize + 1];
	size = strsize;
	for (int i = 0; i < size; i++)
		value[i] = n[i];
	value[size] = '\0';
	return *this;

}

Number& Number::operator+=(const Number& n)
{
	valueInteger += n.valueInteger;
	int y = valueInteger, x = valueInteger, rests = 0, maxBase = max(base, n.base);
	base = maxBase;

	while (y)
	{
		rests++;
		y /= maxBase;
	}

	int* aux = new int[rests];
	int* vector = new int[rests];

	for (int i = 0; i < rests; i++)
	{
		aux[i] = 0;
		vector[i] = 0;
	}

	int i = 0;
	while (x)
	{
		aux[i] = x % maxBase;
		x /= maxBase;
		i++;
	}

	for (int i = 0; i < rests; i++)
		vector[i] = aux[rests - i - 1];

	delete[] value;

	value = new char[rests + 1];
	this->value[rests] = '\0';


	switchFromBase10toBaseB(this, rests, vector);

	size = rests + 1;
	delete[] aux;
	delete[] vector;
	return *this;
}

char Number::operator[](int index)
{
	return this->value[index];
}

bool Number::operator>(const Number& n)
{
	if (valueInteger > n.valueInteger)
		return 1;
	else
		return 0;
}

bool Number::operator<(const Number& n)
{
	if (valueInteger < n.valueInteger)
		return 1;
	else
		return 0;
}

bool Number::operator>=(const Number& n)
{
	if (valueInteger >= n.valueInteger)
		return 1;
	else
		return 0;
}

bool Number::operator<=(const Number& n)
{
	if (valueInteger <= n.valueInteger)
		return 1;
	else
		return 0;
}

bool Number::operator==(const Number& n)
{
	if (valueInteger == n.valueInteger)
		return 1;
	else
		return 0;
}

bool Number::operator!=(const Number& n)
{
	if (valueInteger != n.valueInteger)
		return 1;
	else
		return 0;
}

Number& Number::operator--()
{
	for (int i = 0; i < this->GetDigitsCount() - 2; i++)
		this->value[i] = this->value[i + 1];
	this->value[this->GetDigitsCount() - 2] = '\0';
	return *this;
}

Number& Number::operator--(int value)
{
	this->value[this->GetDigitsCount() - 1] = '\0';
	return *this;
}

void Number::SwitchBase(int newBase)
{
	int rests = 0, x = switchFromBaseBtoBase10(this), y = switchFromBaseBtoBase10(this);
	this->base = newBase;

	while (y)
	{
		rests++;
		y /= newBase;
	}

	int* aux = new int[rests];
	int* vector = new int[rests];

	for (int i = 0; i < rests; i++)
	{
		aux[i] = 0;
		vector[i] = 0;
	}

	int i = 0;
	while (x)
	{
		aux[i] = x % newBase;
		x /= newBase;
		i++;
	}

	for (int i = 0; i < rests; i++)
		vector[i] = aux[rests - i - 1];

	delete[] this->value;

	this->value = new char[rests + 1];
	this->value[rests] = '\0';

	switchFromBase10toBaseB(this, rests, vector);

	this->size = rests + 1;
	delete[] aux;
	delete[] vector;
}

void Number::Print()
{
	for (int i = 0; i < this->size; i++)
		cout << this->value[i];
	cout << '\n';
}