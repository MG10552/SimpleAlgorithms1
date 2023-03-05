// SortowanieBabelkowezNitro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

const int N = 10000; // Liczebnoœæ zbioru.
int TABLE_FILES(int d[], int N)
{
	int i; srand((unsigned)time(NULL));
	for (i = 0; i < N; i++) d[i] = rand() % 10000;
	 return d[N];
}

int main()
{
	int d[N], i, p, pmin, pmax;
	
	//Wyœwietlamy tablicê przed posortowaniem (opcjonalnie, lecz przy tak du¿ych tablicach nie jest to polecane)
	//cout << "Przed sortowaniem:" <<endl; 
	//for (i = 0; i < N; i++) d[i] = rand() % 5000;
	 
	TABLE_FILES(d, N);
	
	//for (i = 0; i < N; i++) cout << setw(4) << d[i];
	cout << endl;
	
	//Rozpoczynamy badanie czasu przed rozpoczêciem algorytmu
	//-------------------BADANIE CZASU-----------------------------------
	__int64 time1, time2, time3, time4, delta1, delta2, frequency1, frequency2;
		QueryPerformanceFrequency((LARGE_INTEGER*)&frequency1);
		QueryPerformanceCounter((LARGE_INTEGER*)&time1);
	//-------------------------------------------------------------------
	//Sortujemy nasz¹ tablicê z dodatkiem stra¿nika
		{ 

			pmin = 0; pmax = N - 1;
			do
			{
				p = -1;
				for (i = pmin; i < pmax; i++)
				if (d[i] > d[i + 1])
				{
					swap(d[i], d[i + 1]);
					if (p < 0) pmin = i;
					p = i;
				}
				if (pmin) pmin--;
				pmax = p;
			} while (p >= 0);
		} 
		
	//Wyœwietlamy wynik sortowania (opcjonalnie, lecz przy tak du¿ych tablicach nie jest to polecane):
	//cout << "Po sortowaniu:" <<endl;
	//for (i = 0; i < N; i++) cout << setw(4) << d[i];
	cout << endl;
	//Teraz obliczamy ile trwa³ nasz algorytm pierwszy
	//-------------------------------------------------------------------
	QueryPerformanceCounter((LARGE_INTEGER*)&time2);
	delta1 = (time2 - time1) / (frequency1 / 1000);
	//-------------------------------------------------------------------
	//Wyœwietlamy wynik naszego badania
	std::cout << "Czas 1: " << delta1 << "ms" << std::endl << "Czestotliwosc procesora 1: " << frequency1 << endl;
	cout << endl;
	//------------------------------------------------------------------------------------------------------------------------------------------
	
	//Rozpoczynamy badanie czasu przed rozpoczêciem algorytmu drugiego
	//-------------------BADANIE CZASU-----------------------------------
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency2);
	QueryPerformanceCounter((LARGE_INTEGER*)&time3);
	//-------------------------------------------------------------------
	//Sortujemy nasz¹ tablicê bez stra¿nika
	{ 
	int i, j, p;
	for (j = N - 1; j > 0; j--)
	{
		p = 1;
		for (i = 0; i < j; i++)
		if (d[i] > d[i + 1])
		{
			swap(d[i], d[i + 1]);
			p = 0;
		}
		if (p) break;
	}
	}
	//Wyœwietlamy wynik sortowania (opcjonalnie, lecz przy tak du¿ych tablicach nie jest to polecane):
	//cout << "Po sortowaniu:" <<endl;
	//for (i = 0; i < N; i++) cout << setw(4) << d[i];
	cout << endl;
	//Teraz obliczamy ile trwa³ nasz algorytm drugi
	//-------------------------------------------------------------------
	QueryPerformanceCounter((LARGE_INTEGER*)&time4);
	delta2 = (time4 - time3) / (frequency2 / 1000);
	//-------------------------------------------------------------------
	//Wyœwietlamy wynik naszego badania
	std::cout << "Czas 2: " << delta2 << "ms" << std::endl << "Czestotliwosc procesora 2: " << frequency2 << endl;
	cout << endl;

	 system("PAUSE");
	return 0;
}

