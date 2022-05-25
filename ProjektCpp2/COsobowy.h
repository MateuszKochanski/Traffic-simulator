#pragma once
#include "CPojazd.h"

/// @file COsobowy.h
/// @brief Plik nag��wkowy klasy COsobowy

/// @brief Klasa samochodu osobowego
class COsobowy : public CPojazd
{
    /// @brief Parametr okre�laj�cy maksymalny jak d�ugo pojazd b�dzie sta� na skrzyzowaniu r�wnorz�dnym
    int cierpliwosc;
public:
    COsobowy(int id, vector <CSkrzyzowanie*> skrzyzowania, CDroga* droga, int odl, int kier);
    ~COsobowy();
    bool sprawdzCzyMogeJechac(vector <CDroga*> drogi, vector <CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc);
};

