#include "Vektor.h"
#include <iostream>
using namespace std;

Vektor::Vektor(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
}
Vektor::Vektor(const Vektor& v)
{
	size = v.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = v.data[i];
	}
	beg = v.beg;
	end = v.end;
}
Vektor::~Vektor()
{
	delete[]data;
	data = nullptr;
}
Vektor& Vektor::operator=(const Vektor& v)
{
	if (this == &v) { return *this; }
	size = v.size;
	if (data != nullptr) { delete[]data; }
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = v.data[i];
	}
	beg = v.beg;
	end = v.end;
	return *this;
}
int& Vektor::operator[](int index)
{
	if (index < size) { return data[index]; }
	else { cout << "Error: index > size" << endl; }
}
Vektor Vektor::operator+(const int k)
{
	Vektor temp(size);
	for (int i = 0; i < size; i++)
	{
		temp.data[i] += data[i] + k;
	}
	return temp;
}

ostream& operator<<(ostream& out, const Vektor& v)
{
	for (int i = 0; i < v.size; ++i)
	{
		out << v.data[i] << " ";
	}
	return out;
}
istream& operator>>(istream& in, Vektor& v)
{
	for (int i = 0; i < v.size; ++i)
	{
		in >> v.data[i];
	}
	return in;
}

int Vektor::operator()()
{
	return size;
}
