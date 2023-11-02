#pragma once
#include <iostream>
#include <stdio.h>
#include "CAvion.h"

class CRessource
{
private:
	bool occupé;
	CAvion* listeAttente;

public:
	CRessource();
	CRessource(CRessource& ressource1);
	~CRessource();
};

