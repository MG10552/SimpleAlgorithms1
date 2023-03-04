// QuickSort2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
using namespace std;

const int N = 50; // Liczebnoœæ zbioru.
//Deklaracja tej samej tablicy dla dwoch roznych sortowan
int d[] = { 50, 67, 89, 33, 73, 31, 63, 69, 92, 33,
			19, 99, 68, 17, 40, 29, 1, 10, 70, 32,
			72, 66, 98, 33, 4, 50, 53, 78, 39, 8, 
			26, 90, 75, 15, 24, 49, 47, 87, 18, 40,
			21, 37, 39, 89, 54, 80, 18, 56, 91, 89 };

int e[] = { 50, 67, 89, 33, 73, 31, 63, 69, 92, 33,
			19, 99, 68, 17, 40, 29, 1, 10, 70, 32,
			72, 66, 98, 33, 4, 50, 53, 78, 39, 8,
			26, 90, 75, 15, 24, 49, 47, 87, 18, 40,
			21, 37, 39, 89, 54, 80, 18, 56, 91, 89 };

//-----------------------HOARE-------------------------
 int partition(int e[], int p, int r) 
{
	int x = e[p]; 
	int i = p, j = r, w; 
	while (true) 
	{
		while (e[j] > x) 
			j--;
		while (e[i] < x) 
			i++;
		if (i < j) 
		{
			w = e[i];
			e[i] = e[j];
			e[j] = w;
			i++;
			j--;
		}
		else 
			return j; 
	}
}

 void Hoare_Sort(int e[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(e, p, r); 
		Hoare_Sort(e, p, q); 
		Hoare_Sort(e, q + 1, r); 
	}
}
//-----------------------------------------------------
//-----------------------LOMUTO------------------------
void Lomuto_Sort(int lewy, int prawy)
{
	int i, j, pivot;

	i = (lewy + prawy) / 2;
	pivot = d[i]; d[i] = d[prawy];
	for (j = i = lewy; i < prawy; i++)
	if (d[i] < pivot)
	{
		swap(d[i], d[j]);
		j++;
	}
	d[prawy] = d[j]; d[j] = pivot;
	if (lewy < j - 1)  Lomuto_Sort(lewy, j - 1);
	if (j + 1 < prawy) Lomuto_Sort(j + 1, prawy);
}
//-----------------------------------------------------
int main()
{
	int i;
	cout << "-------------------------------Przed sortowaniem:-------------------------------" << endl;

	for (i = 0; i < N; i++) d[i];
	for (i = 0; i < N; i++) cout << setw(4) << d[i];

	//Wywo³ujemy funkcjê sortuj¹c¹ 
	Lomuto_Sort(0, N - 1); cout << endl;
	// Wyœwietlamy wynik sortowania
	cout << "Po sortowaniu Lomuto:" << endl;
	for (i = 0; i < N; i++) cout << setw(4) << d[i];
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-------------------------------Przed sortowaniem:-------------------------------" << endl << endl;

	for (i = 0; i < N; i++) e[i];
	for (i = 0; i < N; i++) cout << setw(4) << e[i];

	//Wywo³ujemy funkcjê sortuj¹c¹ 
	Hoare_Sort(e, 0, N - 1); cout << endl;
	// Wyœwietlamy wynik sortowania
	cout << "Po sortowaniu Hoare:" << endl << endl;
	for (i = 0; i < N; i++) cout << setw(4) << e[i];
	cout << endl; 
	cout << "Wnioski?" << endl;
	cout << "Oba Algorytmy zwracaja to samo, tj. posortowan¹ tablicê" << endl;
	system("PAUSE");
	return 0;
}

