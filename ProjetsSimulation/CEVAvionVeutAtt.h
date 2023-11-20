#pragma once
#include "CEvenement.h"
class CEVAvionVeutAtt : public CEvenement
{
private:
	CPisteAtterissage pisteAtterissage;
	CAvion avion;
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

