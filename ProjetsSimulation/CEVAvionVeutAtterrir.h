#pragma once
#include "CEvenement.h"
#include <vector>
#ifndef AvionVeutAtterrir_H
#define AvionVeutAtterrir_H
class CEVAvionVeutAtterrir : public CEvenement
{
private:
	vector<CPisteAtterissage*> pisteAtterissage;
	CAvion *avion;
public :

	CEVAvionVeutAtterrir();
	~CEVAvionVeutAtterrir();
	CEVAvionVeutAtterrir(CAvion p_avion, vector<CPisteAtterissage> p_pistes, time_t p_temp);
	vector<CPisteAtterissage*> LirePisteAtterissage() { return pisteAtterissage; }
	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) {
			*avion= p_avion;
	}
	//Si piste libre et liste d'attente vide peut atterir -> lance CEVAvionAtteris en mettant la piste libre occupée
	void run();
};
#endif 
