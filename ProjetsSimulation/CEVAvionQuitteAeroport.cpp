#include "CEVAvionQuitteAeroport.h"
#include "CEVAvionDecolle.h"
#include "CGestionTemps.h"
#include <windows.h>
double CGestionTemps::tempsRetardDepart = 0;
int CGestionTemps::nbavances = 0;
int CGestionTemps::nbretards = 0;
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
}

void CEVAvionQuitteAeroport::run()
{

	if (!CPisteDecollage::lireListeAttenteAvion().empty()) {
		std::cout << "Avion " << avion->lireIdAvion() << " quitte l'aeroport " << std::endl << std::endl;
		avion->modifierEtat(Etat::PARTI);
		pisteDecollage->modifierOccupation(false);

		*avion = *CPorteEmbarquement::lireListeAttenteAvion().front();
		CEVAvionDecolle AVD(*avion, pisteDecollage, this->lireTempsDebut());
		CGestionTemps::AjouterTempsDepart(difftime(this->lireTempsDebut(), avion->lireHeureDepartPrevue()));
		AVD.run();
		pisteDecollage->retirerAvionListeA();

		
	}
	else {
		std::cout << "Avion " << avion->lireIdAvion() << " quitte l'aeroport " << std::endl << std::endl;
		avion->modifierEtat(Etat::PARTI);
		pisteDecollage->modifierOccupation(false);
		CGestionTemps::AjouterTempsDepart(difftime(this->lireTempsDebut(), avion->lireHeureDepartPrevue()));

	}
	
}
