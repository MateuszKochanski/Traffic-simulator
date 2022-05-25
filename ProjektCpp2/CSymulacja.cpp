#include "CSymulacja.h"

/// @file CSymulacja.cpp
/// @brief Plik �r�d�owy klasy CSymulacja

/// @brief Konstruktor klasy CSymulacja
CSymulacja::CSymulacja()
{
    zarzadaniePojazdami = nullptr;
    czestotliwosc = 100;
    mapa = nullptr;
    start = clock();
    now = 0;
    elapsed = 0;
}

/// @brief Ustawienie parametr�w symulacji
/// @param m Obiekt przechowywuj�cy wszystkie elementy znajduj�ce si� na mapie
/// @param cz Cz�stotliwo�� od�wiezania symulacji
/// @param obs Obserwator klasy zarz�dzaniem pojazd�w
/// @param liczbaPojazdow Liczba pojazd�w jaka ma zosta� stworzona
CSymulacja::CSymulacja(CMapa* m, int cz, CObserwator* obs, int liczbaPojazdow)
{
    mapa = m;
    zarzadaniePojazdami = new CZarzadzaniePojazdami(mapa, liczbaPojazdow);
    zarzadaniePojazdami->attach(obs);
    czestotliwosc = cz;
    start = clock();
    now = 0;
    elapsed = 0;
}

/// @brief Uruchomienie jednego cyklu symulacji
void CSymulacja::uruchom()
{   /*
    now = clock();
    elapsed = double(now - start) / CLOCKS_PER_SEC;
    if (elapsed >= (1.0/double(czestotliwosc)))
    {
        start = now;
        mapa->odswierz(czestotliwosc);
    }   
    */
      //////////////////////////////tymczasowa zmiana  
    do{
    now = clock();
    elapsed = double(now - start) / CLOCKS_PER_SEC;
    }while (elapsed < (1.0 / double(czestotliwosc)));
    start = now;
    odswiez();
}

/// @brief Od�wie�enie sygnalizacji �wietlnych i pojazd�w
void CSymulacja::odswiez()
{
    for (int i = 0; i < mapa->getSkrzyzowania().size(); i++)
    {
        for (int j = 0; j < mapa->getSkrzyzowania()[i]->getSwiatla().size(); j++)
        {
            mapa->getSkrzyzowania()[i]->getSwiatla()[j]->odswiez(czestotliwosc);
        }
    }
    for (int i = 0; i < mapa->getPojazdy().size(); i++)
    {
        mapa->getPojazdy()[i]->odswiez(mapa->getDrogi(), mapa->getSkrzyzowania(), mapa->getPojazdy(), czestotliwosc);
    }
}






