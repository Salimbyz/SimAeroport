#pragma once
#include "CEvenement.h"
#include "CPorteEmbarquement.h"
class CEVAvionVaGate : public CEvenement
{
private:
	CAvion* avion;
	CPorteEmbarquement gate;
public :
	CEVAvionVaGate();
	CEVAvionVaGate(CEVAvionVaGate& p_evAvionVaGate);
	~CEVAvionVaGate();
	CAvion LireAvion();
	CPisteAtterissage LirePisteAtterrissage();
	void ModifierAvion(CAvion p_avion);
	void ModifierGate(CPorteEmbarquement p_gate);
	void run();
};

