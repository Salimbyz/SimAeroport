#pragma once
#include "CEvenement.h"
#ifndef CEVAvionVeutDEbarquer_H
#define CEVAvionVeutDEbarquer_H

class CEVAvionVeutDebarquer : public CEvenement
{
private :
	CAvion* avion;
	CPorteEmbarquement* gate;
public :
	CEVAvionVeutDebarquer();
	CEVAvionVeutDebarquer(CAvion p_avion, CPisteAtterissage p_pisteAtterrissage);
	CEVAvionVeutDebarquer(CEVAvionVeutDebarquer& p_evAvionVeutDebarquer);
	~CEVAvionVeutDebarquer();

	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion);

	CPorteEmbarquement LireGate() { return *gate; }
	void ModifierGate(CPorteEmbarquement p_gate) { *gate = p_gate; }

	void run();

};
#endif 
