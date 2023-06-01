#pragma once
#include<exception>
#include<iostream>
using namespace std;

class exceptie1 : public exception {
	virtual const char* what() const throw()
	{
		return "Index out of bounds!\n";
	}
};

template<class T>
class Array;

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;

};

template<class T>
class ArrayIterator
{
private:
	int Current;
	T** List;
	int Size;
	int Capacity;
public:
	void SetCurrent(int value)
	{
		Current = value;
	}
	ArrayIterator(Array<T>& list)
	{
		Current = 0;
		List = list.GetList();
		Size = list.GetSize();
		Capacity = list.GetCapacity();
		cout << "Size: " << Size << endl;
	}
	ArrayIterator<T>& operator++ ()
	{
		if (Current < Size)
			Current++;
		return *this;
	}
	ArrayIterator<T>& operator-- ()
	{
		if (Current > 0)
			Current--;
		return *this;
	}
	bool operator= (ArrayIterator<T>& other)
	{
		List = other.List;
		Current = other.Current;
		Size = other.Size;
		Capacity = other.Capacity;
		return true;
	}
	bool operator== (ArrayIterator<T>& other)
	{
		return Current == other.Current;
	}
	bool operator!= (ArrayIterator<T>& other)
	{
		return Current != other.Current;
	}
	T* GetElement()
	{
		if (Current == Size)
			return nullptr;
		return List[Current];
	}

};


template<class T>
class Array {
private:
	T** List;
	int Capacity;
	int Size;
public:

	exceptie1 outOfBounds;

	// constructor trivial
	Array() : Capacity(0), Size(0), List(nullptr) {}

	// destructor
	~Array() {
		cout << "Destructor called!\n";
		for (int i = 0; i < Capacity; i++)
			delete List[i];
		if (List != nullptr)
			delete[] List;
		Capacity = Size = 0;
	}

	// array cu dimensiune specificata
	Array(int capacity) {
		List = new T * [capacity];
		for (int i = 0; i < capacity; i++)
			List[i] = new T;
		Capacity = capacity;
		Size = 0;
	}

	// constructor de copiere
	Array(const Array<T>& otherArray)
	{
		cout << "Copy constructor called!\n";
		this->~Array();
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];
		for (int i = 0; i < Capacity; i++)
		{
			List[i] = new T;
			if (i < Size)
			{
				*List[i] = *otherArray.List[i];
			}
		}
	}

	// accesarea elem i
	T& operator[] (int index)
	{
		if (index >= Size || index >= Capacity)
			throw outOfBounds;
		cout << index << endl;
		return *List[index];
	}

	void resize()
	{
		// rebuild Array with 2 * Capacity elements
		T** tempList;
		tempList = new T * [Capacity];
		for (int i = 0; i < Capacity; i++)
			tempList[i] = new T;
		for (int i = 0; i < Size; i++)
			*tempList[i] = *List[i];
		for (int i = 0; i < Capacity; i++)
			delete List[i];
		delete[] List;

		List = new T * [2 * Capacity];
		for (int i = 0; i < 2 * Capacity; i++)
			List[i] = new T;
		for (int i = 0; i < Size; i++)
			*List[i] = *tempList[i];
		for (int i = 0; i < Capacity; i++)
			delete tempList[i];
		delete[] tempList;
		Capacity *= 2;
	}

	// pushBack
	const Array<T>& operator+= (const T& newElem)
	{
		if (Size >= Capacity)
			resize();
		*List[Size] = newElem;
		Size++;
		return *this;
	}

	// insert o valoare pe poz index
	const Array<T>& Insert(int index, const T& newElem)
	{
		if (index >= Size)
			throw outOfBounds;
		if (Size >= Capacity)
			resize();
		for (int i = Size; i > index; i--)
			*List[i] = *List[i - 1];
		*List[index] = newElem;
		Size++;
	}

	// insert o lista pe poz index
	const Array<T>& Insert(int index, const Array<T>& otherArray)
	{
		cout << "trying to insert: " << Size << " " << otherArray.Size << endl;
		if (index >= Size)
			throw outOfBounds;
		int otherSize = otherArray.Size;
		while (Size + otherSize >= Capacity)
		{
			resize();
			cout << "resized to " << Capacity << endl;
		}
		cout << "";
		for (int i = Size + otherSize - 1; i > index + otherSize - 1; i--)
		{
			cout << "List[" << i << "] = List[" << i - otherSize << "]\n";
			*List[i] = *List[i - otherSize];
		}
		cout << "here\n";
		for (int i = index; i < index + otherSize; i++)
		{
			cout << "List[" << i << "] = otherList[" << i - index << "]\n";
			*List[i] = *otherArray.List[i - index];
		}
		cout << "ended insert list function!\n";
		Size += otherSize;
		return *this;
	}

	void debug()
	{
		cout << "DEBUG: " << Size << " / " << Capacity << endl;
		for (int i = 0; i < Size; i++)
			cout << *List[i] << " ";
		cout << endl;
	}

	const Array<T>& Delete(int index)
	{
		if (index >= Size)
			throw outOfBounds;
		for (int i = index; i < Size - 1; i++)
			*List[i] = *List[i + 1];
		Size--;
		return *this;
	}

	bool operator=(const Array<T>& otherArray)
	{
		this->~Array();
		Size = otherArray.Size;
		Capacity = otherArray.Capacity;
		List = new T * [Capacity];
		for (int i = 0; i < Capacity; i++)
		{
			List[i] = new T;
			if (i < Size)
			{
				*List[i] = *otherArray.List[i];
			}
		}
		cout << endl;
		return true;
	}

	// sortare default
	void Sort()
	{
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = i + 1; j < Size; j++)
			{
				if (*List[i] > *List[j])
				{
					T aux = *List[i];
					*List[i] = *List[j];
					*List[j] = aux;
				}
			}
		}
	}

	// sortare cu functie de comparare
	void Sort(int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = i + 1; j < Size; j++)
			{
				if (compare(*List[i], *List[j]))
				{
					T aux = *List[i];
					*List[i] = *List[j];
					*List[j] = aux;
				}
			}
		}
	}

	// sortare cu clasa comparatoare
	void Sort(Compare* comparator)
	{
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = i + 1; j < Size; j++)
			{
				if (comparator->CompareElements(&(*List[i]), &(*List[j])))
				{
					T aux = *List[i];
					*List[i] = *List[j];
					*List[j] = aux;
				}
			}
		}
	}

	// cautare binara default
	int BinarySearch(const T& elem)
	{
		Sort();
		int left = 0, right = Size - 1;
		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (*List[middle] == elem)
				return middle;
			else if (*List[middle] > elem)
				right = middle - 1;
			else
				left = middle + 1;
		}
		return -1;
	}

	// cautare binara cu functie de comparare
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		Sort(compare);
		int left = 0, right = Size - 1;
		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (*List[middle] == elem)
				return middle;
			else if (compare(*List[middle], elem))
				right = middle - 1;
			else
				left = middle + 1;
		}
		return -1;
	}
	// cautare binara cu class Compare
	int BinarySearch(const T& elem, Compare* comparator)
	{
		Sort(comparator);
		int left = 0, right = Size - 1;
		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (*List[middle] == elem)
				return middle;
			T* aux = new T;
			*aux = elem;
			if (comparator->CompareElements(&(*List[middle]), &(*aux))) // error! cannot covert const T to void *
			{
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
			delete aux;
		}
		return -1;
	}

	// cautare secventiala default
	int Find(const T& elem)
	{
		for (int i = 0; i < Size; i++)
		{
			if (*List[i] == elem)
				return i;
		}
		return -1;
	}

	// cautare secventiala cu functie de comparare egal
	int Find(const T& elem, int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < Size; i++)
		{
			if (compare(*List[i], elem))
				return i;
		}
		return -1;
	}

	// cautare secventiala cu clasa de comparare egal
	int Find(const T& elem, Compare* comparator)
	{
		for (int i = 0; i < Size; i++)
		{
			T* aux = new T;
			*aux = elem;
			if (comparator->CompareElements(&(*List[i]), &(*aux)))
			{
				delete aux;
				return i;
			}
			delete aux;
		}
		return -1;
	}
	int GetSize()
	{
		return Size;
	}
	int GetCapacity()
	{
		return Capacity;
	}
	T** GetList()
	{
		return List;
	}


	ArrayIterator<T> GetBeginIterator()
	{
		ArrayIterator<T> tempIt(this);
	}
	ArrayIterator<T> GetEndIterator()
	{
		ArrayIterator<T> tempIt(this);
		tempIt.SetCurrent(Size);
	}
};


