#pragma once
#include "CEvenement.h"
#ifndef CEVAvionVeutDEbarquer_H
#define CEVAvionVeutDEbarquer_H;

class CEVAvionVeutDebarquer : public CEvenement
{
private :
	CAvion* avion;
	CPisteAtterissage* pisteAtterrissage;
public :
	CEVAvionVeutDebarquer();
	CEVAvionVeutDebarquer(CAvion p_avion, CPisteAtterissage p_pisteAtterrissage);
	CEVAvionVeutDebarquer(CEVAvionVeutDebarquer& p_evAvionVeutDebarquer);
	~CEVAvionVeutDebarquer();
	CAvion LireAvion();
	CPisteAtterissage LirePisteAtterrissage();
	void ModifierAvion(CAvion p_avion);
	void ModifierPisteAtterrissage(CPisteAtterissage p_pisteAtterrissage);
	void run();

};
#endif 
