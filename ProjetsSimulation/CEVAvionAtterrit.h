#pragma once
#include "CEvenement.h"
#define TempsAtterisssage = 90
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
	CEVAvionAtterrit(CAvion p_avion, CPisteAtterissage p_pisteAtt, time_t p_temps);
	CPisteAtterissage LirePisteAtterissage() { return *pisteAtterissage; }
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) { *pisteAtterissage = p_pisteAtterissage; }

	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

	//
	void run();

};
#endif // !CEVDebutAtterrissage 


