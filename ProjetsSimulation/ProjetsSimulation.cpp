#pragma once
#include <stdio.h>
#include <string>
#include"CPisteAtterissage.h"
#include "CAvion.h"
#include "CEvenement.h"
#include "CEVAvionVeutAtterrir.h"
#include "CEVAvionVeutDebarquer.h"
#include "CEVAvionVeutDecoller.h"
#include "CEntree.h"

using namespace std;


int main(int argc, char* argv[]) {
	CEntree entree;
	
	string fichierAvion;
	vector<CAvion> listeAvion = entree.lireAvions(fichierAvion);

	string fichierPisteA;
	vector<CPisteAtterissage> listePisteA = entree.lirePisteAtterissage(fichierPisteA);

	string fichierPisteD;
	vector<CPisteDecollage> listePisteD = entree.lirePisteDecollage(fichierPisteD);

	string fichierPorteE;
	vector<CPorteEmbarquement> listePorteE = entree.lirePorteEmbarquement(fichierPorteE);

	//Creation des entités et ressources
	CAvion* Avion1= new CAvion(2, 3, 4, Etat::EN_VOL);
	CAvion* Avion2 = new CAvion(4, 563, 8237, Etat::PARKING);
	CAvion* Avion3 = new CAvion(*Avion2);
	CAvion* Avion4 = new CAvion(*Avion1);
	Avion3->modifierIdAvion(3);
	Avion4->modifierIdAvion(1);
	
	CPisteAtterissage Piste1;
	Piste1.ecrireIdPisteA(1);
	Piste1.ajouterAvionListeA(Avion1);
	Piste1.ajouterAvionListeA(Avion2);
	Piste1.ajouterAvionListeA(Avion3);
	Piste1.ajouterAvionListeA(Avion4);
	CPisteAtterissage Piste2;
	CPisteAtterissage Piste3;
	CPisteAtterissage Piste4;
	CPisteAtterissage Piste5;
	Piste2.ecrireIdPisteA(2);
	Piste3.ecrireIdPisteA(3);
	Piste4.ecrireIdPisteA(4);
	Piste5.ecrireIdPisteA(5);
	vector<CPisteAtterissage> pistes;
	
	pistes.push_back(Piste1);
	pistes.push_back(Piste2);
	pistes.push_back(Piste3);
	pistes.push_back(Piste4);
	pistes.push_back(Piste5);
	
	CAvion avion(5, 5, 5, Etat::EN_VOL);
	//Remplissage des gates
	CPorteEmbarquement Porte1;
	CPorteEmbarquement Porte2;
	CPorteEmbarquement Porte3;
	CPorteEmbarquement Porte4;
	CPorteEmbarquement Porte5;

	Porte1.ecrireIdPorteE(1);
	Porte2.ecrireIdPorteE(2);
	Porte3.ecrireIdPorteE(3);
	Porte4.ecrireIdPorteE(4);
	Porte5.ecrireIdPorteE(5);
	CEVAvionVeutDebarquer::AjouterGate(Porte1);
	CEVAvionVeutDebarquer::AjouterGate(Porte2);
	CEVAvionVeutDebarquer::AjouterGate(Porte3);
	CEVAvionVeutDebarquer::AjouterGate(Porte4);
	CEVAvionVeutDebarquer::AjouterGate(Porte5);

	CPisteDecollage PisteD1;
	CPisteDecollage PisteD2;
	CPisteDecollage PisteD3;
	CPisteDecollage PisteD4;
	CPisteDecollage PisteD5;

	PisteD1.ecrireIdPisteD(1);
	PisteD2.ecrireIdPisteD(2);
	PisteD3.ecrireIdPisteD(3);
	PisteD4.ecrireIdPisteD(4);
	PisteD5.ecrireIdPisteD(5);

	CEVAvionVeutDecoller::AjouterPiste(PisteD1);
	CEVAvionVeutDecoller::AjouterPiste(PisteD2);
	CEVAvionVeutDecoller::AjouterPiste(PisteD3);
	CEVAvionVeutDecoller::AjouterPiste(PisteD4);
	CEVAvionVeutDecoller::AjouterPiste(PisteD5);

	CEVAvionVeutAtterrir EVAVA(*Avion1,pistes, Avion1->lireHeureArriveePrevue());
	EVAVA.run();
	//Piste1.lirePisteAtterissage();
	//Porte1.lirePorteEmbarquement();
	return 0;
}