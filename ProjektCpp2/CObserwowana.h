#pragma once
#include "CObserwator.h"

class CObserwowana
{
	virtual void attach(CObserwator*) = 0;
	virtual void detach(CObserwator*) = 0;
	virtual void notify() = 0;
};

