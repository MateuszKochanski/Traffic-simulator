#pragma once
#include "CPojazd.h"

/// @file COsobowy.h
/// @brief Plik nag³ówkowy klasy COsobowy

/// @brief Klasa samochodu osobowego
class COsobowy : public CPojazd
{
    /// @brief Parametr okreœlaj¹cy maksymalny jak d³ugo pojazd bêdzie sta³ na skrzyzowaniu równorzêdnym
    int cierpliwosc;
public:
    COsobowy(int id, vector <CSkrzyzowanie*> skrzyzowania, CDroga* droga, int odl, int kier);
    ~COsobowy();
    bool sprawdzCzyMogeJechac(vector <CDroga*> drogi, vector <CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc);
};

