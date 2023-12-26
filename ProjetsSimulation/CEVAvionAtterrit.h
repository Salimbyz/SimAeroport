#pragma once
#include "CEvenement.h"
#define TempsAtterisssage = 90;
#ifndef CEVDebutAtterrissage 
#define CEVDebutAtterrissage


class CEVAvionAtterrit: public CEvenement
{
private:
	CPisteAtterissage* pisteAtterissage;
	CAvion* avion;
public:
	CEVAvionAtterrit();
	~CEVAvionAtterrit();
	CEVAvionAtterrit(CEVAvionAtterrit& p_EVAvionVeutAtterir);
	CPisteAtterissage LirePisteAtterissage();
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage);

	CAvion LireAvion();
	void ModifierAvion(CAvion p_avion);

	//
	void run();

};
#endif // !CEVDebutAtterrissage 


