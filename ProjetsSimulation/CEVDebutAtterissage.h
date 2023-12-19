#pragma once
#include "CEvenement.h"
#define TempsAtterisssage = 90;
#ifndef CEVDebutAtterrissage 
#define CEVDebutAtterrissage


class CEVDebutAtterissage : public CEvenement
{
private:
	CPisteAtterissage* pisteAtterissage;
	CAvion* avion;
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
#endif // !CEVDebutAtterrissage 


