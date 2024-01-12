#include "CEVAvionQuittePiste.h"
#include "CEVAvionAtterrit.h"
#include "CEVAvionVeutDebarquer.h"
#include "CEntree.h"
CEVAvionQuittePiste::CEVAvionQuittePiste()
{
	pisteAtterissage = new CPisteAtterissage();
	avion = new CAvion();
}
CEVAvionQuittePiste::CEVAvionQuittePiste(CAvion p_avion, CPisteAtterissage* p_pisteAtterrissage, time_t p_time)
{
	avion = new CAvion(p_avion);
	pisteAtterissage = p_pisteAtterrissage;
	this->ecrireTempsDebut(p_time);
}

CEVAvionQuittePiste::~CEVAvionQuittePiste()
{
	delete avion;
}


void CEVAvionQuittePiste::run() {
	
	if (pisteAtterissage->lireListeAttenteAvion().empty()) {
		std::cout << "Avion " << avion->lireIdAvion() << " quitte la piste " << pisteAtterissage->lireIdPisteA() << " a ";
		CEntree::printTimeT(this->lireTempsDebut());
		avion->modifierEtat(Etat::ATTENTE_PORTE);
		pisteAtterissage->modifierOccupation(false);
		CEVAvionVeutDebarquer EVAVD(*avion,this->lireTempsDebut());
		EVAVD.run();
	}
	else
	{
		std::cout << "Avion " << avion->lireIdAvion() << " quitte la piste " << pisteAtterissage->lireIdPisteA() << " a ";
		CEntree::printTimeT(this->lireTempsDebut());
		avion->modifierEtat(Etat::ATTENTE_PORTE);
		pisteAtterissage->modifierOccupation(false);
		CEVAvionVeutDebarquer EVAVD(*avion, this->lireTempsDebut());
		EVAVD.run();
		
		*avion = *pisteAtterissage->lireListeAttenteAvion().front();
		if (difftime(this->lireTempsDebut(),avion->lireHeureArriveePrevue()) < 300) {
			CEVAvionAtterrit AVA(*avion, pisteAtterissage, this->lireTempsDebut() + 300);
			pisteAtterissage->retirerAvionListeA();
			AVA.run();
		}
		else {
			CEVAvionAtterrit AVA(*avion, pisteAtterissage, this->lireTempsDebut());
			AVA.run();
		}

	}

}