#include "CEVAvionAtterrit.h"
#include "CEVAvionQuittePiste.h"
#include "CEntree.h"
CEVAvionAtterrit::CEVAvionAtterrit() {
	avion = new CAvion();
	pisteAtterissage = new CPisteAtterissage();
}
CEVAvionAtterrit::CEVAvionAtterrit(CAvion p_avion, CPisteAtterissage* p_pisteAtterissage, time_t p_temps) {
	avion = new CAvion(p_avion);
	pisteAtterissage = p_pisteAtterissage;
	this->ecrireTempsDebut(p_temps);
}
CEVAvionAtterrit::~CEVAvionAtterrit() {
	delete avion;
}
//Suite de avion veut atterrir
void CEVAvionAtterrit::run() {
	std::cout << "Avion n " << avion->lireIdAvion() << " atterris sur piste " << pisteAtterissage->lireIdPisteA() << " a ";
	CEntree::printTimeT(this->lireTempsDebut());
	CEVAvionQuittePiste AVQP (*avion, pisteAtterissage, this->lireTempsDebut()+300);
	AVQP.run();
}