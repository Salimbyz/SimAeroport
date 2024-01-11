#pragma once
#include "CEvenement.h"
#ifndef CEVAvionVeutDEbarquer_H
#define CEVAvionVeutDEbarquer_H

class CEVAvionVeutDebarquer : public CEvenement
{
private :
	CAvion* avion;
	static vector<CPorteEmbarquement*> gates;
public :
	CEVAvionVeutDebarquer();
	CEVAvionVeutDebarquer(CAvion p_avion, time_t p_temps);
	~CEVAvionVeutDebarquer();

	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

	vector<CPorteEmbarquement*> LireGates() { return gates; }
	static void LibererPorte(int p_idporte) {

	}
	static void AjouterGate(CPorteEmbarquement p_gate) { 
		CPorteEmbarquement* porteE = new CPorteEmbarquement(p_gate);
		gates.push_back(porteE); }
	void run();

};

#endif 
