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

	CPisteAtterissage LirePisteAtterissage();
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage);

	CAvion LireAvion();
	void ModifierAvion(CAvion p_avion);

	void run();
};