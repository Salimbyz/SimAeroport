#include "CPorteEmbarquement.h"

CPorteEmbarquement::CPorteEmbarquement()
{
	idPorteE = 0;
}

CPorteEmbarquement::CPorteEmbarquement(CPorteEmbarquement& p_porteE)
{
	idPorteE = p_porteE.lireIdPorteE();
}

CPorteEmbarquement::~CPorteEmbarquement()
{
}

void CPorteEmbarquement::ecrireIdPorteE(unsigned int p_idPorteE)
{
	idPorteE = p_idPorteE;
}

unsigned int CPorteEmbarquement::lireIdPorteE()
{
	return idPorteE;
}
