#pragma once
#include <iostream>
#include<queue>
#include "CAvion.h"
#include "CRessource.h"

using namespace std;
class CPorteEmbarquement : public CRessource
{
private :
	unsigned int idPorteE;
	queue<CAvion*> listeAttenteAvion;

public :
	CPorteEmbarquement() :idPorteE(0), listeAttenteAvion() {};
	CPorteEmbarquement(CPorteEmbarquement& p_porteE);
	~CPorteEmbarquement();

	void ecrireIdPorteE(unsigned int p_idPorteE);
	unsigned int lireIdPorteE();

	void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);
	queue<CAvion*> lireListeAttenteAvion();
	
	void ajouterAvionListeA(CAvion* p_avionAjout);
	void retirerAvionListeA();

	void lirePisteAtterissage();
};

