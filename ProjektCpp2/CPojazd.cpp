#include "CPojazd.h"

int CPojazd::getID()
{
	return ID;
}

int CPojazd::getX()
{
	return x;
}

int CPojazd::getY()
{
	return y;
}

int CPojazd::getIDDrogi()
{
	return idDrogi;
}

int CPojazd::getOdleglosc()
{
	return odleglosc;
}

void CPojazd::attach(CObserwator*)
{
}

void CPojazd::detach(CObserwator*)
{
}

void CPojazd::notify()
{
}