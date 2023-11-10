#pragma once
#include <iostream>
#include <time.h>
#include <queue>
#include "CAvion.h"

using namespace std;

class CPisteAtterissage
{
private:
	unsigned int idPisteA;
	queue<CAvion*> ListeAttenteAvion;

public:
	CPisteAtterissage();
	CPisteAtterissage(CPisteAtterissage& p_pisteA);
	~CPisteAtterissage();

	void ecrireIdPisteA(unsigned int p_idPisteA);
	unsigned int lireIdPisteA();

	void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);
	queue<CAvion*> lireListeAttenteAvion();
};

