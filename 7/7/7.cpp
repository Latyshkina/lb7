// 7.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include "rectangle.h"
  
using namespace std;
template<class X>class Set
{
	X *d = new X[0];
	int size = 0;
	int key, count;

public:
	Set() {
		cout << "Set constructor" << endl;
		cout << "Size=";
		cin >> size;
		delete[]d;
		d = new X[size];
		for (int i = 0; i < size; i++)
		{
			d[i] = (X)((double)(rand() % 1000) / 100);
		}
		
	}
	X operator [](int i) { //доступ к элементу 
		return d[i];
	}
	Set(int m)
	{
		delete[]d;
		d = new X[m];
		size = m;

		for (int i = 0; i < size; i++)
		{
			d[i] = (X)((double)(rand() % 1000) / 100);
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				key = j + 1;  count = d[key];
				if (d[j] > d[key])
				{
					d[key] = d[j]; d[j] = count;
				}
			}
		}
	}
	Set(X*q, int m)
	{
		delete[]d;
		d = new X[m];
		size = m;
		for (int i = 0; i < size; i++)
		{
			d[i] = q[i];
		}
	}
	operator int() {
		return size;
	}
	friend Set <X> operator *(Set<X> a, Set<X>b){
		int k = 0;
		for (int i = 0; i < a.size; i++)
		{
			bool y = 1;
			for (int n = 0; n < i; n++)
			{
				if (a.d[i] == a.d[n]) // берем у а массив д
					y = 0;
			}
			if (y == 1)
			{

				for (int n = 0; n < b.size; n++)
				{
					y = 1;
					for (int p = 0; p < n; p++)
					{
						if (b.d[n] == b.d[p]) // берем у а массив д
							y = 0;
					}
					if (y == 1)
					{
						if (a.d[i] == b.d[n])
						{
							k++;
						}
					}
				}
			}
		}
		Set <X> c(k);
		k = 0;
		for (int i = 0; i < a.size; i++)
		{
			bool y = 1;
			for (int n = 0; n < i; n++)
			{
				if (a.d[i] == a.d[n]) // берем у а массив д
					y = 0;
			}
			if (y == 1)
			{
				for (int n = 0; n < b.size; n++)
				{
					y = 1;
					for (int p = 0; p < n; p++)
					{
						if (b.d[n] == b.d[p]) // берем у а массив д
							y = 0;
					}
					if (y == 1)
					{
						if (a.d[i] == b.d[n])
						{
							c.d[k] = a.d[i];
							k++;
						}
					}
				}
			}
		}
		return c;
	};
	Set(const Set <X>&t){
		delete[]d;
		size = t.size;
		d = new X[size];
		for (int i = 0; i<size; i++)
		{
			d[i] = t.d[i];
		}
	}
	~Set()
	{
		delete[]d;
	}
	friend bool operator >(const Set &a, const Set&b){
		for (int i = 0; i < b.size; i++)
		{
			bool y = 0;
			for (int n = 0; n < a.size; n++)
			{
				if (b.d[i] == a.d[n])
				{
					y = 1;
					break;
				}

			}
			if (y == 0)
			{
				return 0;
			}
		}
		return 1;
	}
	friend bool operator <(const Set &a, const Set&b){
		return (b>a);
	}
	void print()
	{
		cout << "{";
		for (int i = 0; i < size; i++)
		{
			if (i != (size - 1))
				cout << d[i] << ", ";
			else
				cout << d[i];
		}
		cout << "}\n";
	}
	template  <class X>  void Min()
	{
		X s;
		s = d[0];
		for (int i = 0; i < size; i++)
		{
			
			if (s > d[i])
			{
				s = d[i];
			}
		}
	cout << "Min=" << s << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << "Множество типа double" << endl;
	Set <double> a(5);
	a.print();
	double *n = new double[6];
	for (int i = 0; i < 6; i++)
	{
		n[i] = ((double)(rand() % 1000) / 100);
	}
	Set <double> b(n, 6);
	b.print();
	//(a*b).print();
	cout << "Множество типа int" << endl;
	Set <int> l(5);
	l.print();
	Set <int> k(5);
	k.print();
	(l*k).print();
	l.Min<int>();
	k.Min<int>();
	a.Min<double>();
	cout << "Множество из прямоугольников" << endl;
	rectangle* arr = new rectangle[4];
	Set <rectangle> c(arr, 4);
	c.print();
	/*	setlocale(LC_ALL, "rus");
	Set<int> a;
	a.print();
	cout << endl;
	cout << "Полученный элемент = ";
	cout << a[3];
	cout << endl;
	cout << "Мощность =" << (int)a << endl;
	Set<int> b;
	b.print();
	cout << endl;
	Set<int> v((Set<int>)(a*b));
	cout << "a*b=";
	v.print();
	cout << endl;
	cout << "Проверка на принадлежность:" << endl;
	cout << (a > b);
	cout << endl;
	cout << (b > v);
	cout << endl;
	cout << "Проверка на подмножество:" << endl;
	cout << (a < b);
	cout << endl;
	cout << (v < b); //  меньше, больше
	cout << endl;
	return 0;*/
}
