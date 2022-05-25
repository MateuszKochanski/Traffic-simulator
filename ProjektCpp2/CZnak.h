#pragma once
/// @file CZnak.h
/// @brief Plik nag��wkowy klasy CZnak

/// @brief Klasa znaku
class CZnak
{
	/// @brief Typ znaku: 'U' - ust�p perwsze�stwo, 'P' - pierwsze�stwo przejazdu, 'R' - rondo
	char typ;
public:
	CZnak(char); 
	char getTyp();
};

