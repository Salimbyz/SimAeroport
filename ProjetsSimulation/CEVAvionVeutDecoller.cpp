#include "CEVAvionVeutDecoller.h"
#include "CEVAvionDecolle.h"

CEVAvionVeutDecoller::CEVAvionVeutDecoller()
{
	avion = new CAvion();
}

CEVAvionVeutDecoller::~CEVAvionVeutDecoller()
{

	delete avion; // Ceci est s�r m�me si avion est NULL

}
CEVAvionVeutDecoller::CEVAvionVeutDecoller(CAvion p_avion, time_t p_temps) {
	avion = new CAvion(p_avion);
	this->ecrireTempsDebut(p_temps);
}
vector<CPisteDecollage*> CEVAvionVeutDecoller::pistesDecollage = vector<CPisteDecollage*>();
void CEVAvionVeutDecoller::run() {
	
	for (unsigned int i = 0; i < pistesDecollage.size() && avion->lireEtat() == Etat::ATTENTE_PISTE; i++) {
		//Liste attente vide, on peut faire d�barquer l'avion
		// ! Voir si possibilit� de !
		if (!pistesDecollage[i]->lireOccupation() &&CPisteDecollage::lireListeAttenteAvion().empty() ) {
			std::cout << "Avion numero " << avion->lireIdAvion() << " se prepare au decollage sur la piste numero " << pistesDecollage[i]->lireIdPisteD() << std::endl;
			avion->modifierEtat(Etat::DECOLLE);
			pistesDecollage[i]->modifierOccupation(true);
			CEVAvionDecolle EVAD(*avion, pistesDecollage[i], this->lireTempsDebut());
			EVAD.run();
		}
		//Liste attente non vide, on fait d�coller le premier avion de la queue
		else if (!pistesDecollage[i]->lireOccupation()) {
			std::cout << "Avion numero " << avion->lireIdAvion() << " se prepare au decollage sur la piste numero " << pistesDecollage[i]->lireIdPisteD() << std::endl;
			pistesDecollage[i]->ajouterAvionListeA(avion);
			pistesDecollage[i]->modifierOccupation(true);
			CEVAvionDecolle EVAD(*(pistesDecollage[i]->lireListeAttenteAvion().front()), pistesDecollage[i], this->lireTempsDebut());
			pistesDecollage[i]->lireListeAttenteAvion().front()->modifierEtat(Etat::DECOLLE);
			pistesDecollage[i]->retirerAvionListeA();
			EVAD.run();
		}
	}
}

