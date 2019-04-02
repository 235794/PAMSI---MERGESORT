#include "mergedec.hh"
#include <cmath>
#include <iostream>

using namespace std;

// FUNKCJA SORTUJACA

template <typename type>
void sortowanie (type tab[], type elemp, type elemo) 
{
  type elemsr;  	// srodkowy element, w ktorym bedzie podzial tablicy
  if(elemp < elemo) 
  {
    elemsr = (elemp + elemo) / 2;      
    sortowanie(tab, elemp, elemsr);    	// rekurencyjne sortowanie mniejszych tablic
    sortowanie(tab, elemsr + 1, elemo); 
    polacz(tab, elemp, elemsr, elemo);  // polaczenie powstalych tablic
  }
}

// FUNKCJA LACZACA TABLICE

template <typename type>
void polacz (type tab[], type elemp, type elemsr, type elemo) 
{
  type i, j, k;                                              
  type rozmiar1 = elemsr - elemp + 1;        // rozmiar tablic po lewej (rozmiar1) i prawej (rozmiar2)
  type rozmiar2 =  elemo - elemsr;

// tworzenie tablic tabpoml - pomocnicza po lewej, tabpomp - pomocnicza po prawej
  type *tabpoml = new type[rozmiar1]; 
  type *tabpomp = new type[rozmiar2];  
 
// kopiowanie danych
   for (i = 0; i < rozmiar1; i++)
   {
        tabpoml[i] = tab[elemp + i];
   }
   for (j = 0; j < rozmiar2; j++)
   {
        tabpomp[j] = tab[elemsr + 1 + j];
   }
 
// laczenie w posortowana tablice: i-tablica po lewej, j- tablica po prawj, k-posotrowana duza tablica
   i = 0;                                        
   j = 0;                                         
   k = elemp;                                  


   while (i < rozmiar1 && j < rozmiar2)    // wybieranie mniejszych elementow i wpisywanie do tablicy
   {
       if (tabpoml[i] <= tabpomp[j])            
       {
            tab[k] = tabpoml[i];                 
            i++;                                    
        }
        else
        {
            tab[k] = tabpomp[j];
            j++;
        }
        k++;  
   }                                      
    

// przepisywanie pozostalych elementow tablic 

    while (i < rozmiar1)
    {
        tab[k] = tabpoml[i];
        i++;
        k++;
    }
 
    while (j < rozmiar2)
    {
        tab[k] = tabpomp[j];
        j++;
        k++;
    }

delete[] tabpoml;
delete[] tabpomp;

}


// FUNKCJA SPRAWDZAJACA

template <typename type>
bool test (type tab[], type rozmiar) 
    {
    bool blad = false;
    for(type i = 0; i < rozmiar - 1; i++) 
	{
        if (tab[i] > tab[i+1]) 
	    {       
            blad = true;              
            }
	}
    return blad;
}
 
 
