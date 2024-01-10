#include "CPorteEmbarquement.h"

queue<CAvion*> CPorteEmbarquement::listeAttenteAvion;

CPorteEmbarquement::CPorteEmbarquement(const CPorteEmbarquement& p_porteE)
{
	idPorteE = p_porteE.idPorteE;
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
		listeAttenteAvion.push(avionTMP);
		p_listeAttenteAvion.pop();
	}
}

queue<CAvion*> CPorteEmbarquement::lireListeAttenteAvion()
{
	return listeAttenteAvion;
}

void CPorteEmbarquement::lirePorteEmbarquement()
{
	queue<CAvion*> temp;
	while (!listeAttenteAvion.empty()) {
		CAvion* AvionTemp = listeAttenteAvion.front();
		temp.push(AvionTemp);
		listeAttenteAvion.pop();
	}
	cout << idPorteE << endl;
	while (!temp.empty()) {
		temp.front()->lireAvion();
		cout << endl;
		temp.pop();
	}
	while (!temp.empty()) {
		delete temp.front();
		temp.pop();
	}
}

void CPorteEmbarquement::ajouterAvionListeA(CAvion* p_avionAjout)
{
	listeAttenteAvion.push(p_avionAjout);
}

void CPorteEmbarquement::retirerAvionListeA()
{
	listeAttenteAvion.pop();
}
