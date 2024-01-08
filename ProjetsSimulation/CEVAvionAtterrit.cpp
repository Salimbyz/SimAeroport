#include "CEVAvionAtterrit.h"
#include "CEVAvionQuittePiste.h"
CEVAvionAtterrit::CEVAvionAtterrit() {
	avion = new CAvion();
	pisteAtterissage = new CPisteAtterissage();
}
CEVAvionAtterrit::CEVAvionAtterrit(CAvion p_avion, CPisteAtterissage p_pisteAtterissage, time_t p_temps) {
	avion = new CAvion(p_avion);
	pisteAtterissage = new CPisteAtterissage(p_pisteAtterissage);
	this->ecrireTempsDebut(p_temps);
}
CEVAvionAtterrit::~CEVAvionAtterrit() {
	delete avion;
	delete pisteAtterissage;
}
//Suite de avion veut atterrir
void CEVAvionAtterrit::run() {
	CEVAvionQuittePiste AVQP (*avion, *pisteAtterissage, this->lireTempsDebut()+90);
	AVQP.run();
}