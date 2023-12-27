#pragma once
#include "CEvenement.h"
#ifndef AvionVeutAtterrir_H
#define AvionVeutAtterrir_H
class CEVAvionVeutAtterrir : public CEvenement
{
private:
	CPisteAtterissage* pisteAtterissage;
	CAvion* avion;
public :

	CEVAvionVeutAtterrir();
	~CEVAvionVeutAtterrir();
	CEVAvionVeutAtterrir(CEVAvionVeutAtterrir& p_EVAvionVeutAtterir);

	CPisteAtterissage LirePisteAtterissage();
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage);

	CAvion LireAvion();
	void ModifierAvion(CAvion p_avion);
	//Si piste libre et liste d'attente vide peut atterir -> lance CEVAvionAtteris en mettant la piste libre occupée
	void run();
};
#endif 
