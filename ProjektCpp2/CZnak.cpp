#include "CZnak.h"

/// @file CZnak.cpp
/// @brief Plik �r�d�owy klasy CZnak

/// @brief Konstruktor klasy CZnak
/// @param a Typ znaku
CZnak::CZnak(char a)
{
	typ = a;
}

/// @brief Zwraca typ znaku
/// @return Typ znaku
char CZnak::getTyp()
{
	return typ;
}
