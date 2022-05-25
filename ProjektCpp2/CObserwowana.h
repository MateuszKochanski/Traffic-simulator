#pragma once
#include "CObserwator.h"

/// @file CObserwowana.h
/// @brief Plik nag��wkowy wirtualnej klasy CObserwowana

/// @brief Klasa interfejsu obserwatora z kt�rej dziedzicz� klasy obserwowane
class CObserwowana
{
	/// @brief Dodanie obserwatora
	/// @param obs Wska�nik do obserwatora
	virtual void attach(CObserwator* obs) = 0;
	/// @brief Usuni�cie obserwatora
	/// @param obs Wska�nik do obserwatora
	virtual void detach(CObserwator* obs) = 0;
	/// @brief Powiadomienie obserwator�w
	virtual void notify() = 0;
};

