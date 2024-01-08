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
	static queue<CAvion*> listeAttenteAvion;

public:
	CPisteAtterissage() :idPisteA(0) {};
	CPisteAtterissage(const CPisteAtterissage& p_pisteA);
	CPisteAtterissage(unsigned int p_id);
	~CPisteAtterissage();

	void ecrireIdPisteA(unsigned int p_idPisteA);
	unsigned int lireIdPisteA();

	static void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);
	static queue<CAvion*> lireListeAttenteAvion();

	void ajouterAvionListeA(CAvion* p_avionAjout);
	void retirerAvionListeA();

	void lirePisteAtterissage();
};

