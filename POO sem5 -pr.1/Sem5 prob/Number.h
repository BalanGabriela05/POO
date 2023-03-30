#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Number
{
    int size;
    char* value;
    int base;
    int valueInteger;

public:

    Number(const char* value, int base);
    Number(int value);
    ~Number();
    Number(const Number& n); //copy
    Number(Number&& n); //move

    friend int switchFromBaseBtoBase10(Number* n);
    friend void switchFromBase10toBaseB(Number* n, int rests, int* vector);

    Number operator+ (const Number& n);
    Number operator- (const Number& n);
    Number& operator= (const Number& n);
    Number& operator= (int n);
    Number& operator= (const char* n);
    Number& operator+= (const Number& n);
    char operator[] (int index);
    bool operator> (const Number& n);
    bool operator< (const Number& n);
    bool operator>= (const Number& n);
    bool operator<= (const Number& n);
    bool operator== (const Number& n);
    bool operator!= (const Number& n);
    Number& operator-- ();
    Number& operator-- (int value);

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount();
    int  GetBase();
};