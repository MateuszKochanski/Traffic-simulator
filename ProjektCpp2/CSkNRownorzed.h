#pragma once
#include "CSkrzyzowanie.h"
#include "CZnak.h"

class CSkNRownorzed :
    public CSkrzyzowanie
{
    vector <CZnak*> znaki;

public:
    void co();
    void update(int, int);

};

