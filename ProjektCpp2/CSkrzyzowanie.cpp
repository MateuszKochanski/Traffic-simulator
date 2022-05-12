#include "CSkrzyzowanie.h"

int CSkrzyzowanie::getID()
{
	return ID;
}

int CSkrzyzowanie::getX()
{
	return x;
}

int CSkrzyzowanie::getY()
{
	return y;
}

void CSkrzyzowanie::set(int id, int ix, int iy,int t)
{
	ID = id;
	x = ix;
	y = iy;
	typ = t;
}

int CSkrzyzowanie::getTyp()
{
	return typ;
}

vector <int> CSkrzyzowanie::getIdDrogi()
{
	return id_dorogi;
}
