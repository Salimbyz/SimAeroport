#pragma once
#include <stdio.h>
#include"CPisteAtterissage.h"
#include "CAvion.h"


using namespace std;


int main(int argc, char* argv[]) {
	CAvion* Avion1= new CAvion(2, 3, 4, Etat::EN_VOL);
	CAvion* Avion2 = new CAvion(4, 563, 8237, Etat::PARKING);
	CAvion* Avion3 = new CAvion(*Avion2);
	CAvion* Avion4 = new CAvion(*Avion1);

	CPisteAtterissage Piste1;
	Piste1.ecrireIdPisteA(3);
	Piste1.ajouterAvionListeA(Avion1);
	Piste1.ajouterAvionListeA(Avion2);
	Piste1.ajouterAvionListeA(Avion3);
	Piste1.ajouterAvionListeA(Avion4);

	Piste1.lirePisteAtterissage();
	return 0;
}