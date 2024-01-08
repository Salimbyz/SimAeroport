#include "CEVAvionQuittePiste.h"
#include "CEVAvionVeutDebarquer.h"
CEVAvionQuittePiste::CEVAvionQuittePiste()
{
	pisteAtterissage = new CPisteAtterissage();
	avion = new CAvion();
}
CEVAvionQuittePiste::CEVAvionQuittePiste(CAvion p_avion, CPisteAtterissage p_pisteAtterrissage, time_t p_time)
{
	avion = new CAvion(p_avion);
	pisteAtterissage = new CPisteAtterissage(p_pisteAtterrissage);
	this->ecrireTempsDebut(p_time);
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


void CEVAvionQuittePiste::run() {
	pisteAtterissage->modifierOccupation(false);

}