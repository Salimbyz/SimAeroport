#pragma once
#include <stdio.h>
#include"CPisteAtterissage.h"
#include "CAvion.h"
#include "CEvenement.h"
#include "CEVAvionVeutAtterrir.h"


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
	CPisteAtterissage Piste2;
	CPisteAtterissage Piste3;
	vector<CPisteAtterissage> pistes;
	pistes.push_back(Piste1);
	pistes.push_back(Piste2);
	pistes.push_back(Piste3);
	/*
	CAvion avion(5, 5, 5, Etat::EN_VOL);
	CEVAvionVeutAtterrir EVAVA(*Avion1,pistes, Avion1->lireHeureArriveePrevue());
	EVAVA.run();*/
	Piste1.lirePisteAtterissage();
	return 0;
}