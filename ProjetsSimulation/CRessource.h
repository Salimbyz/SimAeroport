#pragma once
#include <iostream>
#include <stdio.h>
#include "CAvion.h"

class CRessource
{
private:
	bool occupe;
	CAvion* listeAttente;

public:
	CRessource();
	CRessource(CRessource& p_ressource);
	~CRessource();

	void modifierOccupation(bool p_occupe);
	bool lireOccupation();

	void modifierListeAttente(CAvion* p_listeAttente);
	CAvion* lireListeAttente();
};

