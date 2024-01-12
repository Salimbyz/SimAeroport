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
	//Lecture des entités et ressources par la création d'un
	string fichierAvion;
	vector<CAvion> listeAvion = entree.lireAvions("C:/Users/toro5/source/repos/SimAeroport/Avion.txt");

	string fichierPisteA;
	vector<CPisteAtterissage> listePisteA = entree.lirePisteAtterissage("C:/Users/toro5/source/repos/SimAeroport/Piste Atterissage.txt");

	string fichierPisteD;
	vector<CPisteDecollage> listePisteD = entree.lirePisteDecollage("C:/Users/toro5/source/repos/SimAeroport/Piste Décollage.txt");

	string fichierPorteE;
	vector<CPorteEmbarquement> listePorteE = entree.lirePorteEmbarquement("C:/Users/toro5/source/repos/SimAeroport/Porte Embarquement.txt");
		
	while (!listePisteA.empty()) {

		CEVAvionVeutAtterrir::AjouterPiste(listePisteA.back());
		listePisteA.pop_back();
	}
	while (!listePisteD.empty()) {

		CEVAvionVeutDecoller::AjouterPiste(listePisteD.back());
		listePisteD.pop_back();
	}
	while (!listePorteE.empty()) {

		CEVAvionVeutDebarquer::AjouterGate(listePorteE.back());
		listePorteE.pop_back();
	}
	//Une moyenne de retard de 11 minutes (ministere des transports), pour 20 avions, 28.1% de retards
	vector<int> retards = entree.genererRetardsPoisson(660, 20, 0.281);

	CEVAvionVeutAtterrir AVE(listeAvion.back(), listeAvion.back().lireHeureArriveePrevue()+retards.back());
	listeAvion.pop_back();

	AVE.run();


	while (!listeAvion.empty()) {

		//génération retard arrivée

		AVE.ModifierAvion(listeAvion.back());
		AVE.ecrireTempsDebut(listeAvion.back().lireHeureArriveePrevue()+retards.back());
		AVE.run();
		listeAvion.pop_back();
		retards.pop_back();
	}
	/*
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
	*/
	return 0;
}