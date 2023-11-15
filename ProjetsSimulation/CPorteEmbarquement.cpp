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

void CPorteEmbarquement::ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion)
{
	while (!p_listeAttenteAvion.empty()) {
		CAvion* avionTMP = new CAvion(*p_listeAttenteAvion.front());
		ListeAttenteAvion.push(avionTMP);
		p_listeAttenteAvion.pop();
	}
}

queue<CAvion*> CPorteEmbarquement::lireListeAttenteAvion()
{
	return move(ListeAttenteAvion);
}
