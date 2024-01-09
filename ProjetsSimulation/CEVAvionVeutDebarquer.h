#pragma once
#include "CEvenement.h"
#ifndef CEVAvionVeutDEbarquer_H
#define CEVAvionVeutDEbarquer_H

class CEVAvionVeutDebarquer : public CEvenement
{
private :
	CAvion* avion;
	vector<CPorteEmbarquement*> gates;
public :
	CEVAvionVeutDebarquer();
	CEVAvionVeutDebarquer(CAvion p_avion, vector<CPorteEmbarquement> p_gates, time_t p_temps);
	~CEVAvionVeutDebarquer();

	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

	vector<CPorteEmbarquement*> LireGates() { return gates; }
	void ModifierGates(vector<CPorteEmbarquement*> p_gate) { gates = p_gate; }

	void run();

};
#endif 
