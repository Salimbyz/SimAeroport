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
	CEVAvionVaGate(CEVAvionVaGate& p_evAvionVaGate);
	~CEVAvionVaGate();

	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

	CPorteEmbarquement LirePisteAtterrissage() { return *gate; }
	void ModifierGate(CPorteEmbarquement p_gate) { *gate = p_gate; }
	void run();
};

