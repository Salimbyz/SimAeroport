#include "CEVAvionQuittePiste.h"
#include "CEVAvionAtterrit.h"
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

//Il faut vérifier que la queue de la piste est vide avant de changer d'état
void CEVAvionQuittePiste::run() {
	
	if (pisteAtterissage->lireListeAttenteAvion().empty()) {
		std::cout << "Avion " << avion->lireIdAvion() << " quitte la piste " << pisteAtterissage->lireIdPisteA() << std::endl;
		avion->modifierEtat(Etat::ATTENTE_PORTE);
		pisteAtterissage->modifierOccupation(false);
		CEVAvionVeutDebarquer EVAVD(*avion,this->lireTempsDebut());
		EVAVD.run();
	}
	else if (!pisteAtterissage->lireListeAttenteAvion().empty()){
		std::cout << "Avion " << avion->lireIdAvion() << " quitte la piste " << pisteAtterissage->lireIdPisteA() << std::endl;
		avion->modifierEtat(Etat::ATTENTE_PORTE);
		pisteAtterissage->modifierOccupation(false);
		CEVAvionVeutDebarquer EVAVD(*avion, this->lireTempsDebut());
		EVAVD.run();
		/*
		*avion = *pisteAtterissage->lireListeAttenteAvion().front();

		//ERREUR ICI
		CEVAvionAtterrit AVA(*avion, *pisteAtterissage, this->lireTempsDebut());
		
		AVA.run();*/
	}

}