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
	CRessource(const CRessource& p_ressource);
	CRessource(bool p_occupe);
	~CRessource();

	void modifierOccupation(bool p_occupe);
	bool lireOccupation();
};

