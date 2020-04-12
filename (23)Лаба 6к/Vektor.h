#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class Vektor;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	void operator++() { ++elem; };
	void operator--() { --elem; }
	int& operator*()const { return*elem; }
private:
	int* elem;
};

class Vektor
{
public:
	Vektor(int s, int k = 0);
	Vektor(const Vektor& v);
	~Vektor();
	Vektor& operator=(const Vektor& v);
	int& operator[](int index);
	Vektor operator+(const int k);
	int operator()();
	friend  ostream& operator<<(ostream& out, const Vektor& v);
	friend istream& operator>>(istream& in, Vektor& v);
	Iterator first() { return beg; }
	Iterator last() { return end; }
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};


