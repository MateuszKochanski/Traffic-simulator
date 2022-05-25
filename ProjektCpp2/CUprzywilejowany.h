#pragma once
#include "CPojazd.h"

/// @file CUprzywilejowany.h
/// @brief Plik nag³ówkowy klasy CUprzywilejowany

/// @brief Klasa pojazdu uprzywilejowanego
class CUprzywilejowany : public CPojazd
{
public:
    CUprzywilejowany(int id, vector <CSkrzyzowanie*> skrzyzowania, CDroga* droga, int odl, int kier);
    ~CUprzywilejowany();
    bool sprawdzCzyMogeJechac(vector <CDroga*> drogi, vector <CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc);
};

