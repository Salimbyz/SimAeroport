#pragma once
#include <iostream>
#include <queue>
#include "CAvion.h"
#include "CRessource.h"

using namespace std;
class CPisteDecollage : public CRessource
{
private:
	unsigned int idPisteD;
	static queue<CAvion*> listeAttenteAvion;

public:
	CPisteDecollage() :idPisteD(0){};
	CPisteDecollage(const CPisteDecollage& p_pisteD);
	~CPisteDecollage();

	void ecrireIdPisteD(unsigned int p_idPisteD);
	unsigned int lireIdPisteD();

	static void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);
	static queue<CAvion*> lireListeAttenteAvion();

	void ajouterAvionListeA(CAvion* p_avionAjout);
	void retirerAvionListeA();

	void lirePisteAtterissage();
};

