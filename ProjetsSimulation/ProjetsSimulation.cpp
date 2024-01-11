#pragma once
#include <stdio.h>
#include"CPisteAtterissage.h"
#include "CAvion.h"
#include "CEvenement.h"
#include "CEVAvionVeutAtterrir.h"
#include "CEVAvionVeutDebarquer.h"
#include "CEVAvionVeutDecoller.h"

using namespace std;


int main(int argc, char* argv[]) {

	//Creation des entités et ressources
	CAvion* Avion1= new CAvion(2, 3, 4, Etat::EN_VOL);
	CAvion* Avion2 = new CAvion(4, 563, 8237, Etat::PARKING);
	CAvion* Avion3 = new CAvion(*Avion2);
	CAvion* Avion4 = new CAvion(*Avion1);
	Avion3->modifierIdAvion(3);
	Avion4->modifierIdAvion(1);
	
	CPisteAtterissage Piste1;
	Piste1.ecrireIdPisteA(1);
	CPisteAtterissage Piste2;
	CPisteAtterissage Piste3;

	Piste2.ecrireIdPisteA(2);
	Piste3.ecrireIdPisteA(3);

	vector<CPisteAtterissage> pistes;
	
	

	
	CAvion avion(5, 5, 5, Etat::EN_VOL);
	//Remplissage des gates
	CPorteEmbarquement Porte1;
	CPorteEmbarquement Porte2;


	Porte1.ecrireIdPorteE(1);
	Porte2.ecrireIdPorteE(2);

	CEVAvionVeutDebarquer::AjouterGate(Porte1);
	CEVAvionVeutDebarquer::AjouterGate(Porte2);


	CPisteDecollage PisteD1;
	CPisteDecollage PisteD2;
	CPisteDecollage PisteD3;

	PisteD1.ecrireIdPisteD(1);
	PisteD2.ecrireIdPisteD(2);
	PisteD3.ecrireIdPisteD(3);

	CEVAvionVeutDecoller::AjouterPiste(PisteD1);
	CEVAvionVeutDecoller::AjouterPiste(PisteD2);
	CEVAvionVeutDecoller::AjouterPiste(PisteD3);

	CEVAvionVeutAtterrir::AjouterPiste(Piste1);
	CEVAvionVeutAtterrir::AjouterPiste(Piste2);
	Avion1->modifierEtat(Etat::EN_VOL);
	Avion2->modifierEtat(Etat::EN_VOL);
	Avion3->modifierEtat(Etat::EN_VOL);
	Avion4->modifierEtat(Etat::EN_VOL);

	//A Modifier par une queue d'avions et un lancement en fonction
	CEVAvionVeutAtterrir e;
	CEVAvionVeutAtterrir EVAVA(*Avion1, Avion1->lireHeureArriveePrevue());
	EVAVA.run();

	CEVAvionVeutAtterrir EVAVA2(*Avion2, Avion1->lireHeureArriveePrevue());
	EVAVA2.run();
	CEVAvionVeutAtterrir EVAVA3(*Avion3, Avion1->lireHeureArriveePrevue());
	EVAVA3.run();
	CEVAvionVeutAtterrir EVAVA4(*Avion4, Avion1->lireHeureArriveePrevue());
	EVAVA4.run();

	return 0;
}