#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList n;
	n.Init();
	n.Add(10);
	n.Add(5);
	n.Add(3);
	n.Add(16);
	n.Add(9);
	n.Add(18);
	n.Add(7);
	n.Add(8);
	n.Add(15);
	n.Add(20);
	n.Add(21);
	n.Sort();
	n.Print();


	return 0;
}