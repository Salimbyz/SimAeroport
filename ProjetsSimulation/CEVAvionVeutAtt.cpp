#include "CEVAvionVeutAtt.h"

CEVAvionVeutAtt::CEVAvionVeutAtt()
{
	pisteAtterissage = new CPisteAtterissage();
	avion = new CAvion();
}

CEVAvionVeutAtt::~CEVAvionVeutAtt()
{
	delete avion;
	delete pisteAtterissage;
}

CEVAvionVeutAtt::CEVAvionVeutAtt(CEVAvionVeutAtt& p_EVAvionVeutAtterir)
{
	avion = new CAvion();
	pisteAtterissage = new CPisteAtterissage();

	*avion = p_EVAvionVeutAtterir.LireAvion();
	*pisteAtterissage = p_EVAvionVeutAtterir.LirePisteAtterissage();

}
CAvion CEVAvionVeutAtt::LireAvion() {
	return *avion;
}
CPisteAtterissage CEVAvionVeutAtt::LirePisteAtterissage() {
	return *pisteAtterissage;
}

void CEVAvionVeutAtt::ModifierAvion(CAvion p_avion) {
	*avion = p_avion;
}

void CEVAvionVeutAtt::ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) {
	*pisteAtterissage = p_pisteAtterissage;
}

void CEVAvionVeutAtt::run() {
	if()
}