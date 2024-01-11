#pragma once
#include "CEvenement.h"
#include "CPorteEmbarquement.h"
class CEVAvionVaGate : public CEvenement
{
private:
	CAvion* avion;
	CPorteEmbarquement* gate;
public :
	CEVAvionVaGate();
	CEVAvionVaGate(CAvion p_avion, CPorteEmbarquement* p_porte, time_t p_temps);
	~CEVAvionVaGate();

	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

	CPorteEmbarquement LirePisteAtterrissage() { return *gate; }
	void ModifierGate(CPorteEmbarquement p_gate) { *gate = p_gate; }
	void run();
};

