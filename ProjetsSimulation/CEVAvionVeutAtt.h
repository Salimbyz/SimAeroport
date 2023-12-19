#pragma once
#include "CEvenement.h"
#ifndef AvionVeutAtterir_H
#define AvionVeutAtterir_H
class CEVAvionVeutAtt : public CEvenement
{
private:
	CPisteAtterissage* pisteAtterissage;
	CAvion* avion;
public :

	CEVAvionVeutAtt();
	~CEVAvionVeutAtt();
	CEVAvionVeutAtt(CEVAvionVeutAtt & p_EVAvionVeutAtterir);

	CPisteAtterissage LirePisteAtterissage();
	void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage);

	CAvion LireAvion();
	void ModifierAvion(CAvion p_avion);

	void run();
};
#endif 
