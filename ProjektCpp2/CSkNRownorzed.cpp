#include "CSkNRownorzed.h"

void CSkNRownorzed::co()
{
	cout << "CSkNRownorzed" << endl;
}

void CSkNRownorzed::update(int id, int pierw)
{
	id_dorogi.push_back(id);
	znaki.push_back(new CZnak(pierw));
}

