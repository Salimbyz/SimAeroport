#pragma once
#include "CEvenement.h"
#ifndef AvionVeutAtterrir_H
#define AvionVeutAtterrir_H
class CEVAvionVeutAtterrir : public CEvenement
{
private:
	CPisteAtterissage *pisteAtterissage;
	CAvion *avion;
public :

	CEVAvionVeutAtterrir();
	~CEVAvionVeutAtterrir();
	CEVAvionVeutAtterrir(CAvion p_avion);
	CPisteAtterissage LirePisteAtterissage() { return *pisteAtterissage; }
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) {
		*pisteAtterissage = p_pisteAtterissage;
	}

	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) {
			*avion= p_avion;
	}
	//Si piste libre et liste d'attente vide peut atterir -> lance CEVAvionAtteris en mettant la piste libre occupée
	void run();
};
#endif 
