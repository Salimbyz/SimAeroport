#include "CEVAvionQuitteGate.h"

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
