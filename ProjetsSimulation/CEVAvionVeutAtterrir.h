#pragma once
#include "CEvenement.h"
#include <vector>
#ifndef AvionVeutAtterrir_H
#define AvionVeutAtterrir_H
class CEVAvionVeutAtterrir : public CEvenement
{
private:
	static vector<CPisteAtterissage*> pisteAtterissage;
	CAvion *avion;
public :

	CEVAvionVeutAtterrir();
	~CEVAvionVeutAtterrir();
	CEVAvionVeutAtterrir(CAvion p_avion, time_t p_temp);
	static void AjouterPiste(CPisteAtterissage p_pisteA) { 
		CPisteAtterissage* p_piste = new CPisteAtterissage(p_pisteA);
		pisteAtterissage.push_back(p_piste); 
	}
	static vector<CPisteAtterissage*> LirePisteAtterissage() { return pisteAtterissage; }
	CAvion LireAvion() { return *avion; }
	void ModifierAvion(CAvion p_avion) {
			*avion= p_avion;
	}
	//Si piste libre et liste d'attente vide peut atterir -> lance CEVAvionAtteris en mettant la piste libre occupée
	void run();
};
#endif 
