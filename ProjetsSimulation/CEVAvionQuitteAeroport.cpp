#include "CEVAvionQuitteAeroport.h"
#include "CEVAvionDecolle.h"
#include "CGestionTemps.h"
CEVAvionQuitteAeroport::CEVAvionQuitteAeroport()
{
	pisteDecollage = new CPisteDecollage();
	avion = new CAvion();
}

CEVAvionQuitteAeroport::CEVAvionQuitteAeroport(CAvion p_avion, CPisteDecollage* p_pisteD, time_t p_temps) {
	avion = new CAvion(p_avion);
	pisteDecollage = p_pisteD;
	this->ecrireTempsDebut(p_temps);
}
CEVAvionQuitteAeroport::~CEVAvionQuitteAeroport()
{
	delete(avion);
	delete(pisteDecollage);
}

void CEVAvionQuitteAeroport::run()
{

	if (!CPisteDecollage::lireListeAttenteAvion().empty()) {
		std::cout << "Avion " << avion->lireIdAvion() << " quitte l'aeroport " << std::endl;
		avion->modifierEtat(Etat::PARTI);
		pisteDecollage->modifierOccupation(false);
		*avion = *CPorteEmbarquement::lireListeAttenteAvion().front();
		CEVAvionDecolle AVD(*avion, pisteDecollage, this->lireTempsDebut()+300);
		AVD.run();
		pisteDecollage->retirerAvionListeA();
	}
	else {
		std::cout << "Avion " << avion->lireIdAvion() << " quitte l'aeroport " << std::endl;
		avion->modifierEtat(Etat::PARTI);
		pisteDecollage->modifierOccupation(false);
	}
}
