#pragma once
#ifndef AvionVeutAtterir_H
#define AvionVeutAtterir_H;
#define TempsAtterisssage = 90;
#include "CEvenement.h"


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
