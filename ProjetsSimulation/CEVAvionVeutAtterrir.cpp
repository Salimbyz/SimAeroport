#include "CEVAvionVeutAtterrir.h"
#include "CEVAvionAtterrit.h"
CEVAvionVeutAtterrir::CEVAvionVeutAtterrir()
{
	pisteAtterissage = vector<CPisteAtterissage*>();
	avion = new CAvion();
}
CEVAvionVeutAtterrir::CEVAvionVeutAtterrir(CAvion p_avion, vector<CPisteAtterissage> p_pistes, time_t p_temps) {
	avion = new CAvion(p_avion);
	pisteAtterissage.resize(p_pistes.size());
	for (int i = 0; i < pisteAtterissage.size(); i++) {
		*pisteAtterissage[i] = p_pistes[i];
	}
	this->ecrireTempsDebut(p_temps);
}
CEVAvionVeutAtterrir::~CEVAvionVeutAtterrir()
{
	if (pisteAtterissage.size() != 0) {
		pisteAtterissage.clear();
	}
	if (avion != NULL) {
		delete(avion);
	}

}
void CEVAvionVeutAtterrir::run() {
	for (int i = 0; i < pisteAtterissage.size(); i++) {
		if (!pisteAtterissage[i]->lireOccupation() && pisteAtterissage[i]->lireListeAttenteAvion().empty()) {
			pisteAtterissage[i]->modifierOccupation(true);
			CEVAvionAtterrit EVAA(*avion, *pisteAtterissage[i], this->lireTempsDebut());
			EVAA.run();
		}
		else if (!pisteAtterissage[i]->lireListeAttenteAvion().empty()) {
			pisteAtterissage[i]->modifierOccupation(true);
			CEVAvionAtterrit EVAA(*(pisteAtterissage[i]->lireListeAttenteAvion().front()), *pisteAtterissage[i], this->lireTempsDebut());
			pisteAtterissage[i]->retirerAvionListeA();
			EVAA.run();
		}

	}
}