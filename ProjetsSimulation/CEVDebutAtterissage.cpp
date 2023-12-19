#include "CEVDebutAtterissage.h"
CEVDebutAtterissage::CEVDebutAtterissage()
{
	pisteAtterissage = new CPisteAtterissage();
	avion = new CAvion();
}

CEVDebutAtterissage::~CEVDebutAtterissage()
{
	delete avion;
	delete pisteAtterissage;
}

CEVDebutAtterissage::CEVDebutAtterissage(CEVDebutAtterissage& p_EVAvionVeutAtterir)
{
	avion = new CAvion();
	pisteAtterissage = new CPisteAtterissage();

	*avion = p_EVAvionVeutAtterir.LireAvion();
	*pisteAtterissage = p_EVAvionVeutAtterir.LirePisteAtterissage();

}
CAvion CEVDebutAtterissage::LireAvion() {
	return *avion;
}
CPisteAtterissage CEVDebutAtterissage::LirePisteAtterissage() {
	return *pisteAtterissage;
}

void CEVDebutAtterissage::ModifierAvion(CAvion p_avion) {
	*avion = p_avion;
}

void CEVDebutAtterissage::ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) {
	*pisteAtterissage = p_pisteAtterissage;
}

void CEVDebutAtterissage::run() {

}