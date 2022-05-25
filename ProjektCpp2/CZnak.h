#pragma once
/// @file CZnak.h
/// @brief Plik nagłówkowy klasy CZnak

/// @brief Klasa znaku
class CZnak
{
	/// @brief Typ znaku: 'U' - ustąp perwszeństwo, 'P' - pierwszeństwo przejazdu, 'R' - rondo
	char typ;
public:
	CZnak(char); 
	char getTyp();
};

