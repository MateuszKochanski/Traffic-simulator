#pragma once
#include "CObserwator.h"
#include "CGrafika.h"


class CZarzadzanieGrafika : public CObserwator
{
	CGrafika* grafika;
public:
	CZarzadzanieGrafika(CGrafika* gr);
	void update(int arg);
};

