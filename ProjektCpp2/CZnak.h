#pragma once
/// @file CZnak.h
/// @brief Plik nag³ówkowy klasy CZnak

/// @brief Klasa znaku
class CZnak
{
	/// @brief Typ znaku: 'U' - ust¹p perwszeñstwo, 'P' - pierwszeñstwo przejazdu, 'R' - rondo
	char typ;
public:
	CZnak(char); 
	char getTyp();
};

