#pragma once
#include "CEvenement.h"
class CEVDebutAtterissage : public CEvenement
{
private:
	CPisteAtterissage pisteAtterissage;
	CAvion avion;
public:
	CEVDebutAtterissage();
	~CEVDebutAtterissage();
	CEVDebutAtterissage(CEVDebutAtterissage& p_EVAvionVeutAtterir);

	CPisteAtterissage LirePisteAtterissage();
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage);

	CAvion LireAvion();
	void ModifierAvion(CAvion p_avion);

	void run();
};


