#include "CEVAvionVeutAtterrir.h"
#include "CEVAvionAtterrit.h"
CEVAvionVeutAtterrir::CEVAvionVeutAtterrir()
{
	pisteAtterissage = vector<CPisteAtterissage>();
	avion = new CAvion();
}
CEVAvionVeutAtterrir::CEVAvionVeutAtterrir(CAvion p_avion, vector<CPisteAtterissage> p_pistes, time_t p_temps) {
	avion = new CAvion(p_avion);
	pisteAtterissage = vector<CPisteAtterissage>();
	pisteAtterissage.resize(p_pistes.size());
	for (int i = 0; i < pisteAtterissage.size(); i++) {
		pisteAtterissage[i] = p_pistes[i];
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
	std::cout << "Avion " << avion->lireIdAvion() << " veut atterrir\n";
	for (int i = 0; i < pisteAtterissage.size() && avion->lireEtat() == Etat::EN_VOL; i++) {
		if (!pisteAtterissage[i].lireOccupation() && pisteAtterissage[i].lireListeAttenteAvion().empty()) {
			std::cout << "Avion" << avion->lireIdAvion() << " va atterrir sur " << pisteAtterissage[i].lireIdPisteA() << " a " << this->lireTempsDebut() << "\n";
			avion->modifierEtat(Etat::ATTERRIT);
			pisteAtterissage[i].modifierOccupation(true);
			CEVAvionAtterrit EVAA(*avion, pisteAtterissage[i], this->lireTempsDebut());
			EVAA.run();
		}
		else if (!pisteAtterissage[i].lireOccupation()) {
			pisteAtterissage[i].ajouterAvionListeA(avion);
			pisteAtterissage[i].modifierOccupation(true);
			CEVAvionAtterrit EVAA(*(pisteAtterissage[i].lireListeAttenteAvion().front()), pisteAtterissage[i], this->lireTempsDebut());
			int n = pisteAtterissage[i].lireListeAttenteAvion().front()->lireIdAvion();
			pisteAtterissage[i].lireListeAttenteAvion().front()->modifierEtat(Etat::ATTERRIT);
			pisteAtterissage[i].retirerAvionListeA();
			std::cout << "Avion " << n << " va atterrir sur " << pisteAtterissage[i].lireIdPisteA() << " a " << this->lireTempsDebut() << "\n";
			EVAA.run();
			const time_t t = this->lireTempsDebut();
			
		}
		//Ajout exception

	}
}