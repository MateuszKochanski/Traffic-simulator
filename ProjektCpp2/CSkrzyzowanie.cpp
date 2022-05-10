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

void CSkrzyzowanie::set(int id, int ix, int iy)
{
	ID = id;
	x = ix;
	y = iy;
}