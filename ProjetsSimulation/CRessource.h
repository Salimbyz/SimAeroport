#pragma once
#include <iostream>
#include <stdio.h>
#include "CAvion.h"

class CRessource
{
private:
	bool occupe;

public:
	CRessource();
	CRessource(CRessource& p_ressource);
	~CRessource();

	void modifierOccupation(bool p_occupe);
	bool lireOccupation();
};

