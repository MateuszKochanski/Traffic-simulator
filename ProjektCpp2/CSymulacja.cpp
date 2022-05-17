#include "CSymulacja.h"

CSymulacja::CSymulacja()
{
    zarzadaniePojazdami = nullptr;
    czestotliwosc = 100;
    mapa = nullptr;
    start = clock();
    now = 0;
    elapsed = 0;
}

CSymulacja::CSymulacja(CMapa* m, int cz, CObserwator* obs)
{
    mapa = m;
    zarzadaniePojazdami = new CZarzadzaniePojazdami(mapa);
    zarzadaniePojazdami->attach(obs);
    czestotliwosc = cz;
    start = clock();
    now = 0;
    elapsed = 0;
}

void CSymulacja::setMapa(CMapa* m, int cz)
{
    mapa = m;
    czestotliwosc = cz;
    zarzadaniePojazdami = new CZarzadzaniePojazdami(mapa);
}

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
    mapa->odswierz(czestotliwosc);
}






