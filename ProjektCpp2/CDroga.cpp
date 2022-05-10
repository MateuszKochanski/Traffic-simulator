#include "CDroga.h"

CDroga::CDroga(int id, int s1, int s2, int dl)
{
	ID = id;
	id_Sk[0] = s1;
	id_Sk[1] = s2;
	dlugosc = dl;
}

int CDroga::getID()
{
	return ID;
}
int CDroga::getDlugosc()
{
	return dlugosc;
}