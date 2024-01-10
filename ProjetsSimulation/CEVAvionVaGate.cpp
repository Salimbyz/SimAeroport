#include "CEVAvionVaGate.h"
#include "CEVAvionQuitteGate.h"
CEVAvionVaGate::CEVAvionVaGate() {
	avion = new CAvion();
	gate = new CPorteEmbarquement();
}
CEVAvionVaGate::CEVAvionVaGate(CAvion p_avion, CPorteEmbarquement p_gate, time_t p_temps) {
	avion = new CAvion(p_avion);
	gate = new CPorteEmbarquement(p_gate);
	this->ecrireTempsDebut(p_temps);
}
CEVAvionVaGate::~CEVAvionVaGate() {
	delete (avion);
	delete (gate);
}
void CEVAvionVaGate::run() {
	CEVAvionQuitteGate AVQG(*avion, *gate, this->lireTempsDebut() + 90);
	std::cout << "Avion numero " << avion->lireIdAvion() << " va a la porte d'embarquement numero " <<gate->lireIdPorteE() << std::endl;
	AVQG.run();
}