#include "CEVAvionVeutAtterrir.h"
#include "CEVAvionAtterrit.h"
CEVAvionVeutAtterrir::CEVAvionVeutAtterrir() : avion(new CAvion()) {}

CEVAvionVeutAtterrir::~CEVAvionVeutAtterrir() {
	if (!pisteAtterissage.empty()) {
		pisteAtterissage.clear();
	}
	delete avion; // Ceci est sûr même si avion est NULL
}
vector<CPisteAtterissage*> CEVAvionVeutAtterrir::pisteAtterissage = vector<CPisteAtterissage*>();
CEVAvionVeutAtterrir::CEVAvionVeutAtterrir(CAvion p_avion, time_t p_temps) {
	avion = new CAvion(p_avion);
	this->ecrireTempsDebut(p_temps);
}
void CEVAvionVeutAtterrir::run() {
	for (unsigned int i = 0; i < pisteAtterissage.size() && avion->lireEtat() == Etat::EN_VOL; i++) {
		if (!pisteAtterissage[i]->lireOccupation() && pisteAtterissage[i]->lireListeAttenteAvion().empty()) {
			std::cout << "Avion" << avion->lireIdAvion() << " va atterrir sur " << pisteAtterissage[i]->lireIdPisteA() << " a " << this->lireTempsDebut() << "\n";
			avion->modifierEtat(Etat::ATTERRIT);
			pisteAtterissage[i]->modifierOccupation(true);
			CEVAvionAtterrit EVAA(*avion, pisteAtterissage[i], this->lireTempsDebut());
			EVAA.run();
		}
		else if (!pisteAtterissage[i]->lireOccupation()) {
			pisteAtterissage[i]->ajouterAvionListeA(avion);
			pisteAtterissage[i]->modifierOccupation(true);
			CEVAvionAtterrit EVAA(*(pisteAtterissage[i]->lireListeAttenteAvion().front()), pisteAtterissage[i], this->lireTempsDebut());
			int n = pisteAtterissage[i]->lireListeAttenteAvion().front()->lireIdAvion();
			pisteAtterissage[i]->lireListeAttenteAvion().front()->modifierEtat(Etat::ATTERRIT);
			pisteAtterissage[i]->retirerAvionListeA();
			std::cout << "Avion " << n << " va atterrir sur " << pisteAtterissage[i]->lireIdPisteA() << " a " << this->lireTempsDebut() << "\n";
			EVAA.run();
		}
	}
}