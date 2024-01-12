#include "CEVAvionQuitteAeroport.h"
#include "CEVAvionDecolle.h"
CEVAvionQuitteAeroport::CEVAvionQuitteAeroport()
{
	pisteD = new CPisteDecollage();
	avion = new CAvion();
}

CEVAvionQuitteAeroport::CEVAvionQuitteAeroport(CAvion p_avion, CPisteDecollage* p_pisteD, time_t p_temps)
{
	avion = new CAvion(p_avion);
	pisteD = p_pisteD;
	this->ecrireTempsDebut(p_temps);
}

CEVAvionQuitteAeroport::~CEVAvionQuitteAeroport()
{
	delete(avion);
	delete(pisteD);
}

void CEVAvionQuitteAeroport::run()
{
	std::cout << "Avion " << avion->lireIdAvion() << " quitte l'aeroport " << std::endl;
	avion->modifierEtat(Etat::ATTENTE_PISTE);
	pisteD->modifierOccupation(false);
	if (!pisteD->lireListeAttenteAvion().empty()) {
		*avion = *CPorteEmbarquement::lireListeAttenteAvion().front();
		CEVAvionDecolle AVD(*avion, pisteD, this->lireTempsDebut());
		AVD.run();
		pisteD->retirerAvionListeA();
	}
}
