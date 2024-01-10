#include "CEVAvionQuitteGate.h"
#include "CEVAvionVeutDecoller.h"

CEVAvionQuitteGate::CEVAvionQuitteGate()
{
	avion = new CAvion();
	gate = new CPorteEmbarquement();
}

CEVAvionQuitteGate::CEVAvionQuitteGate(CAvion p_avion, CPorteEmbarquement p_gate, time_t p_temps)
{
	avion = new CAvion(p_avion);
	gate = new CPorteEmbarquement(p_gate);
	this->ecrireTempsDebut(p_temps);
}

CEVAvionQuitteGate::~CEVAvionQuitteGate()
{
	delete(gate);
	delete(avion);
}

void CEVAvionQuitteGate::run()
{
	if (gate->lireListeAttenteAvion().empty()) {
		std::cout << "Avion " << avion->lireIdAvion() << " quitte la porte numero " << gate->lireIdPorteE() << std::endl;
		avion->modifierEtat(Etat::ATTENTE_PISTE);
		gate->modifierOccupation(false);
		CEVAvionVeutDecoller EVAVD(*avion, this->lireTempsDebut());
		EVAVD.run();
	}
	else if (!gate->lireListeAttenteAvion().empty()) {
		std::cout << "Avion " << avion->lireIdAvion() << " quitte la porte numero " << gate->lireIdPorteE() << std::endl;
		avion->modifierEtat(Etat::ATTENTE_PISTE);
		gate->modifierOccupation(false);
		CEVAvionVeutDecoller EVAVD(*avion, this->lireTempsDebut());
		EVAVD.run();
		/*
		*avion = *pisteAtterissage->lireListeAttenteAvion().front();

		//ERREUR ICI
		CEVAvionAtterrit AVA(*avion, *pisteAtterissage, this->lireTempsDebut());

		AVA.run();*/
	}
}
