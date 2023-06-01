#include "Array.h"
#include<cmath>
using namespace std;

int f(const int& a, const int& b)
{
	return abs(a - 7) > abs(b - 7);
}

int g(const int& a, const int& b)
{
	return a == b;
}

class MyCompare : public Compare {
public:
	virtual int CompareElements(void* e1, void* e2) {
		int* a = (int*)e1;
		int* b = (int*)e2;
		return (*a > *b);
	}
};

class MyCompare2 : public Compare {
	virtual int CompareElements(void* e1, void* e2) {
		int* a = (int*)e1;
		int* b = (int*)e2;
		return (*a == *b);
	}
};

int main()
{

	Array<int> A = Array<int>(4);
	for (int i = 10; i >= 0; i -= 2)
		A += i;
	A.debug();
	A.Sort();
	A.debug();

	Array<int> B = Array<int>(10);
	B += 1; B += 3; B += 5;
	A.Insert(3, B);
	A.Delete(0);
	A.debug();

	MyCompare2 compareA;
	cout << A.Find(5, &compareA) << endl;

	ArrayIterator<int> iter(A);
	while (iter.GetElement() != nullptr)
	{
		cout << *iter.GetElement() << " ";
		++iter;
	}



	return 0;
}
