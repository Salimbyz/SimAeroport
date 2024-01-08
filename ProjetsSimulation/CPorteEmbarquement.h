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
	static queue<CAvion*> listeAttenteAvion;

public :
	CPorteEmbarquement() :idPorteE(0){};
	CPorteEmbarquement(const CPorteEmbarquement& p_porteE);
	~CPorteEmbarquement();

	void ecrireIdPorteE(unsigned int p_idPorteE);
	unsigned int lireIdPorteE();

	static void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);
	static queue<CAvion*> lireListeAttenteAvion();
	
	void ajouterAvionListeA(CAvion* p_avionAjout);
	void retirerAvionListeA();

	void lirePisteAtterissage();
};

