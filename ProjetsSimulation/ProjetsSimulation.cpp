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
#include "CGestionTemps.h"
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
	int nbRetardsArrivee = 0;
	long retard = 0;
	for (int i = 0; i < retards.size(); i++) {
		if (retards[i] > 0) {
			nbRetardsArrivee++;
		}
		retard += retards[i];
	}
	std::cout << nbRetardsArrivee << " Avions arrivent en retard et " << 20-nbRetardsArrivee << " arrivent a l'heure, pour un total de " << retard << " secondes" << std::endl << std::endl;
	CEVAvionVeutAtterrir AVE(listeAvion.back(), listeAvion.back().lireHeureArriveePrevue()+retards.back());
	listeAvion.pop_back();

	AVE.run();


	while (!listeAvion.empty()) {
		//génération retard arrivée

		AVE.ModifierAvion(listeAvion.back());
		AVE.ecrireTempsDebut(listeAvion.back().lireHeureArriveePrevue()+retards.back());
		retards.pop_back();
		AVE.run();
		listeAvion.pop_back();

	}
	CGestionTemps::AfficherTempsRetardTotal();
	return 0;
}