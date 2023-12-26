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

	CPisteAtterissage LirePisteAtterissage();
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage);

	CAvion LireAvion();
	void ModifierAvion(CAvion p_avion);

	void run();
};