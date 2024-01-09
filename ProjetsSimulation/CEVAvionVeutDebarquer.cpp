#include "CEVAvionVeutDebarquer.h"

CEVAvionVeutDebarquer::CEVAvionVeutDebarquer()
{
	avion = new CAvion();
	gates = vector<CPorteEmbarquement*>();
}

CEVAvionVeutDebarquer::CEVAvionVeutDebarquer(CAvion p_avion, vector<CPorteEmbarquement> p_gates, time_t p_temps)
{
	avion = new CAvion(p_avion);
	gates.resize(p_gates.size());
	for (int i = 0; i < gates.size(); i++) {
		*gates[i] = p_gates[i];
	}
	this->ecrireTempsDebut(p_temps);
}

CEVAvionVeutDebarquer::~CEVAvionVeutDebarquer()
{
	delete(avion);
	for (int i = 0; i < gates.size(); i++) {
		delete(gates[i]);
	}
	gates.clear();
}

void CEVAvionVeutDebarquer::run()
{
	
}
