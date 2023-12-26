#include "CEVAvionVeutAtterrir.h"
#include "CEVAvionAtterrit.h"
CEVAvionVeutAtterrir::CEVAvionVeutAtterrir()
{
	pisteAtterissage = new CPisteAtterissage();
	avion = new CAvion();
}

CEVAvionVeutAtterrir::~CEVAvionVeutAtterrir()
{
	delete avion;
	delete pisteAtterissage;
}

CEVAvionVeutAtterrir::CEVAvionVeutAtterrir(CEVAvionVeutAtterrir& p_EVAvionVeutAtterir)
{
	avion = new CAvion();
	pisteAtterissage = new CPisteAtterissage();

	*avion = p_EVAvionVeutAtterir.LireAvion();
	*pisteAtterissage = p_EVAvionVeutAtterir.LirePisteAtterissage();

}
CAvion CEVAvionVeutAtterrir::LireAvion() {
	return *avion;
}
CPisteAtterissage CEVAvionVeutAtterrir::LirePisteAtterissage() {
	return *pisteAtterissage;
}

void CEVAvionVeutAtterrir::ModifierAvion(CAvion p_avion) {
	*avion = p_avion;
}

void CEVAvionVeutAtterrir::ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) {
	*pisteAtterissage = p_pisteAtterissage;
}

void CEVAvionVeutAtterrir::run() {
	//A remplacer par une liste de piste valables dans le main
	const int n = 4;
	CPisteAtterissage* ListePiste[n];
	
	for (int i = 0; i < n; i++) {
		if (ListePiste[i]->lireOccupation() && ListePiste[i]->lireListeAttenteAvion().empty()) {
			std::cout << "Debut atterrissage"
			CEVAvionAtterrit* avionAtterrit = new CEVAvionAtterrit();
			avionAtterrit->ecrireTempsDebut();
			avionAtterrit->ModifierAvion(*avion);
			avionAtterrit->ModifierPisteAtterissage(*pisteAtterissage);			
		}
		else if(ListePiste[i]->lireOccupation()) {
			//CPisteAtterrissage.listeAttente.add(CAvion)
			//
		}
	}

}