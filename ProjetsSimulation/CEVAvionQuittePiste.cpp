#include "CEVAvionQuittePiste.h"
CEVAvionQuittePiste::CEVAvionQuittePiste()
{
	pisteAtterissage = new CPisteAtterissage();
	avion = new CAvion();
}

CEVAvionQuittePiste::~CEVAvionQuittePiste()
{
	delete avion;
	delete pisteAtterissage;
}

CEVAvionQuittePiste::CEVAvionQuittePiste(CEVAvionQuittePiste& p_EVAvionVeutAtterir)
{
	avion = new CAvion();
	pisteAtterissage = new CPisteAtterissage();

	*avion = p_EVAvionVeutAtterir.LireAvion();
	*pisteAtterissage = p_EVAvionVeutAtterir.LirePisteAtterissage();

}
CAvion CEVAvionQuittePiste::LireAvion() {
	return *avion;
}
CPisteAtterissage CEVAvionQuittePiste::LirePisteAtterissage() {
	return *pisteAtterissage;
}

void CEVAvionQuittePiste::ModifierAvion(CAvion p_avion) {
	*avion = p_avion;
}

void CEVAvionQuittePiste::ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) {
	*pisteAtterissage = p_pisteAtterissage;
}

void CEVAvionQuittePiste::run() {

}