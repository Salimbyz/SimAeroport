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
	CEVAvionQuittePiste(CEVAvionQuittePiste& p_EVAvionQuittePiste);
	CEVAvionQuittePiste(CAvion p_avion, CPisteAtterissage p_pisteAtterrissage);

	CPisteAtterissage LirePisteAtterissage() { return *pisteAtterissage; }
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) { *pisteAtterissage = p_pisteAtterissage; }

	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

	void run();
};