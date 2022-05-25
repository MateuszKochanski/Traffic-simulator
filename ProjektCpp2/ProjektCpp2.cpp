//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
#include <iostream>
#include "CMapa.h"
#include "CGrafika.h"
#include "CWczytywaczMapy.h"
#include "CSymulacja.h"
#include "CZarzadzanieGrafika.h"
#include "CWyswietlanie.h"

/**
* \mainpage
* \par Projekt z Przedmiotu PJC
* Symulator ruchu drogowego
* \author Mateusz Kochański
* \date 22.05.2022
* \version 1.0
* \par Kontakt :
* \a 01150977@pw.edu.pl
* \par Cel projektu
* Program powstał w celu realizacji projektu z przedmiotu PJC.
* \n Jego zadaniem jest symulacja ruchu pojazdów po wybranej mapie
* \par Instrukcja
* Aby uruchomić symulację należy najpierw wybrać mapę po której poruszać się będą pojazdy za pomocą konsoli programu, następnie wybrać całkowitą liczbę pojazdów które mają się wygenerować. 
* \n Gdy wpisane dane są poprawne zostanie wyświetlona mapa z poruszającymi się po niej pojazdami.
*/

/**
* @file ProjektCpp2.cpp
* @brief Główna funkcja programu
*/



using namespace std;

void wczytajUstawieniaPoczatkowe(int& m, int& lp);

/**
* @brief Główna funkcja programu
*/

int main()
{

    int nrMapy;
    int liczbaPojazdow;
       
    CMapa mapa;
    CGrafika grafika;
    CZarzadzanieGrafika zarzadzaczGrafika(&grafika, &mapa);
    mapa.attach(&zarzadzaczGrafika);

    wczytajUstawieniaPoczatkowe(nrMapy, liczbaPojazdow);

    if (nrMapy == 1)
    {
        CWczytywaczMapy wczytywacz(&mapa, "mapa1.txt");
    }
    else if (nrMapy == 2)
    {
        CWczytywaczMapy wczytywacz(&mapa, "mapa2.txt");
    }
    else
    {
        CWczytywaczMapy wczytywacz(&mapa, "mapa3.txt");
    }

    CSymulacja symulacja(&mapa, 100, &zarzadzaczGrafika, liczbaPojazdow);
    CWyswietlanie okno;

    while (okno.czyJestOtwarte())
    {
        symulacja.uruchom();
        okno.wyswietl(&grafika);
    }
 
    return 0;
}


/**
* @brief Funkcja wczytujące parametry dla symuacji
* @param nrMapy Numer wybranej mapy
* @param liczbaPojazdow Liczba pojazdów w symulacji
*/
void wczytajUstawieniaPoczatkowe(int& nrMapy, int& liczbaPojazdow)
{
    string dane;
    bool daneOK = true;

    cout << "Podaj numer mapy [1-3]: ";
    cin >> dane;

    do
    {
        daneOK = true;
        for (int i = 0; i < dane.size(); i++)
        {
            if (dane[i] < '0' || dane[i] > '9')
            {
                daneOK = false;
            }
        }

        if (daneOK)
        {
            nrMapy = stoi(dane);
            if (nrMapy < 1 || nrMapy > 3)
            {
                daneOK = false;
            }
        }

        if (!daneOK)
        {
            system("cls");
            cout << "Podaj poprawna wartosc [1-3]: ";
            dane.clear();
            cin >> dane;
        }

    } while (!daneOK);

    cout << "Podaj liczbę pojazdów [1-300]:";
    cin >> dane;
    do
    {
        daneOK = true;
        for (int i = 0; i < dane.size(); i++)
        {
            if (dane[i] < '0' || dane[i] > '9')
            {
                daneOK = false;
            }
        }

        if (daneOK)
        {
            liczbaPojazdow = stoi(dane);
            if (liczbaPojazdow < 1 || liczbaPojazdow > 300)
            {
                daneOK = false;
            }
        }

        if (!daneOK)
        {
            system("cls");
            cout << "Podaj poprawna wartosc [1-300]: ";
            dane.clear();
            cin >> dane;
        }

    } while (!daneOK);

}