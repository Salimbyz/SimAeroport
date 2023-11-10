#pragma once
#include<queue>
#include "CAvion.h"

using namespace std;
class CPorteEmbarquement
{
private :
	unsigned int idPorteE;
	queue<CAvion*> ListeAttenteAvion;

public :
	CPorteEmbarquement();
	CPorteEmbarquement(CPorteEmbarquement& p_porteE);
	~CPorteEmbarquement();

	void ecrireIdPorteE(unsigned int p_idPorteE);
	unsigned int lireIdPorteE();

	void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);
	queue<CAvion*> lireListeAttenteAvion();
};

