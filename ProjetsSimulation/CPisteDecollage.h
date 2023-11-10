#pragma once
#include <queue>
#include "CAvion.h"

using namespace std;
class CPisteDecollage
{
private: 
	unsigned int idPisteD;
	queue<CAvion*> ListeAttenteAvion;

public :
	CPisteDecollage();
	CPisteDecollage(CPisteDecollage& p_pisteD);
	~CPisteDecollage();

	void ecrireIdPisteD(unsigned int p_idPisteD);
	unsigned int lireIdPisteD();

	void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);
	queue<CAvion*> lireListeAttenteAvion();
};

