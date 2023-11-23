#pragma once
#include <iostream>
#include <time.h>
#include <queue>
#include "CAvion.h"
#include "CRessource.h"

using namespace std;

class CPisteAtterissage : public CRessource 
{
private:
	unsigned int idPisteA;
	queue<CAvion*> listeAttenteAvion;

public:
	CPisteAtterissage() :idPisteA(0), listeAttenteAvion() {};
	CPisteAtterissage(CPisteAtterissage& p_pisteA);
	~CPisteAtterissage();

	void ecrireIdPisteA(unsigned int p_idPisteA);
	unsigned int lireIdPisteA();

	void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);
	queue<CAvion*> lireListeAttenteAvion();

	void ajouterAvionListeA(CAvion* p_avionAjout);
	void retirerAvionListeA();

	void lirePisteAtterissage();
};

