#pragma once

/// @file CObserwator.h
/// @brief Plik nag³ówkowy wirtualnej klasy CObserwator

/// @brief Klasa interfejsu obserwatora z której dziedzicz¹ klasy obserwatorów
class CObserwator
{
public:
	/// @brief Uaktualnienie obserwatora
	/// @param arg Argument ró¿ny w zale¿noœci od wykorzystania
	virtual void update( int arg) = 0;
};

