#pragma once

/// @file CObserwator.h
/// @brief Plik nag��wkowy wirtualnej klasy CObserwator

/// @brief Klasa interfejsu obserwatora z kt�rej dziedzicz� klasy obserwator�w
class CObserwator
{
public:
	/// @brief Uaktualnienie obserwatora
	/// @param arg Argument r�ny w zale�no�ci od wykorzystania
	virtual void update( int arg) = 0;
};

