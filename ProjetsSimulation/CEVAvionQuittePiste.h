#pragma once
#include "CEvenement.h"
class CEVAvionQuittePiste : public CEvenement
{
private:
	CPisteAtterissage* pisteAtterissage;
	CAvion* avion;
public:

	CEVAvionQuittePiste();
	~CEVAvionQuittePiste();
	CEVAvionQuittePiste(CAvion p_avion, CPisteAtterissage* p_pisteAtterrissage, time_t p_time);

	CPisteAtterissage LirePisteAtterissage() { return *pisteAtterissage; }
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) { *pisteAtterissage = p_pisteAtterissage; }

	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

	void run();
};