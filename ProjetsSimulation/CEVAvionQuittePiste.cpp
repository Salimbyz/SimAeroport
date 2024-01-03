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

void CEVAvionQuittePiste::run() {

}