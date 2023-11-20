#include "CPorteEmbarquement.h"

CPorteEmbarquement::CPorteEmbarquement(CPorteEmbarquement& p_porteE) : listeAttenteAvion()
{
	idPorteE = p_porteE.lireIdPorteE();
}

CPorteEmbarquement::~CPorteEmbarquement()
{
	while (!listeAttenteAvion.empty()) {
		delete listeAttenteAvion.front();
		listeAttenteAvion.pop();
	}
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
		listeAttenteAvion.push(avionTMP);
		p_listeAttenteAvion.pop();
	}
}

queue<CAvion*> CPorteEmbarquement::lireListeAttenteAvion()
{
	return move(listeAttenteAvion);
}
