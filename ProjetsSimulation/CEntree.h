#pragma once
#include <iostream>
#include <time.h>

#include "CAvion.h"
#include "CPisteAtterissage.h"
#include "CPisteDecollage.h"
#include "CPorteEmbarquement.h"

class CEntree
{
private:

public:
	CEntree();
	CEntree(CEntree& Entree1);
	~CEntree();

	vector<CPisteAtterissage> lirePisteAtterissage(const char* p_nomfichier);
};