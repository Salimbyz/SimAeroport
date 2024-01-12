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
	//Boucle tant que qui s'arrêtera une fois que la liste d'attente passé en paramètre sera vidé
	while (!p_listeAttenteAvion.empty()) {
		CAvion* avionTMP = new CAvion(*p_listeAttenteAvion.front());// Création d'un objet CAvion temporaire correspondant au premier avion de la liste d'attente
		listeAttenteAvion.push(avionTMP);//Ajout de l'avion dans la liste attente de notre objet
		p_listeAttenteAvion.pop();//On supprime l'élément récupéré de la liste d'attente paramètre.
		delete avionTMP;//Destruction de l'avion temporaire
	}
}

queue<CAvion*> CPorteEmbarquement::lireListeAttenteAvion()
{
	return listeAttenteAvion;
}

void CPorteEmbarquement::ajouterAvionListeA(CAvion* p_avionAjout)
{
	listeAttenteAvion.push(p_avionAjout);
}

void CPorteEmbarquement::retirerAvionListeA()
{
	listeAttenteAvion.pop();
}
