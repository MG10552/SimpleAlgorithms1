#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
using namespace std;

const int N = 10000; 
void Bubblesortwithboost(int *tab, int i, int j){}

void Bubblesort(int *tab)
{
	int i, j, p;
	 for(j = N - 1; j > 0; j--)
  {
    p = 1;
    for(i = 0; i < j; i++)
      if(tab[i] > tab[i+1])
      {
        swap(tab[i], tab[i+1]);
        p = 0;
      }
    if(p) break;
  }
}

int main()
{
	 int tab[N],i,j,p; 
    
    srand(time(NULL)); 
    
  //  for(int i=0; i<N; tab[i]=rand()%N, i++); 
    
  //  for(int i=0; i<N; printf("%d ", tab[i]), i++); 
/*  int tab[N],i,j,p;
  */
  srand((unsigned)time(NULL));

  for(i = 0; i < N; i++) tab[i] = rand() % 100;
 /* for(i = 0; i < N; i++) cout << setw(4) << d[i];*/ //for(int i=0; i<N; printf("%d ", tab[i]), i++); 
  cout << endl;
//--------------------pomiar czasu---------------------------
  __int64 time1, time2, delta, frequency;
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&time1);
//-----------------------------------------------------------

// Sortujemy
Bubblesort(tab);
  
 //------------------------------------------------------------
  QueryPerformanceCounter((LARGE_INTEGER*)&time2);
	delta=(time2-time1)/(frequency/1000);
	std::cout << "Czas sortowania wynosi: " << delta << "ms" << std::endl << frequency;
 //------------------------------------------------------------

//--------------------pomiar czasu---------------------------
  __int64 time1, time2, delta, frequency;
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&time1);
//-----------------------------------------------------------

// Sortujemy
Bubblesortwithboost(tab);
  
 //------------------------------------------------------------
  QueryPerformanceCounter((LARGE_INTEGER*)&time2);
	delta=(time2-time1)/(frequency/1000);
	std::cout << "Czas sortowania wynosi: " << delta << "ms" << std::endl << frequency;
 //------------------------------------------------------------









//  cout << "Po sortowaniu:\n\n";
 // for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;
  system("pause");
  return 0;
} 

