#pragma once
#include<queue>
#include "CAvion.h"

using namespace std;
class CPorteEmbarquement
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
	void lirePisteAtterissage();
	void ajouterAvionListeA(CAvion* p_avionAjout);
	void retirerAvionListeA();
};

