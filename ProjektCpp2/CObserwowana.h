#pragma once
#include "CObserwator.h"

/// @file CObserwowana.h
/// @brief Plik nag³ówkowy wirtualnej klasy CObserwowana

/// @brief Klasa interfejsu obserwatora z której dziedzicz¹ klasy obserwowane
class CObserwowana
{
	/// @brief Dodanie obserwatora
	/// @param obs WskaŸnik do obserwatora
	virtual void attach(CObserwator* obs) = 0;
	/// @brief Usuniêcie obserwatora
	/// @param obs WskaŸnik do obserwatora
	virtual void detach(CObserwator* obs) = 0;
	/// @brief Powiadomienie obserwatorów
	virtual void notify() = 0;
};

