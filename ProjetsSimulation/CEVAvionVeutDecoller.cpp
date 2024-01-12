#include "CEVAvionVeutDecoller.h"
#include "CEVAvionDecolle.h"

CEVAvionVeutDecoller::CEVAvionVeutDecoller()
{
	avion = new CAvion();
}

CEVAvionVeutDecoller::~CEVAvionVeutDecoller()
{
	delete(avion);

}
CEVAvionVeutDecoller::CEVAvionVeutDecoller(CAvion p_avion, time_t p_temps) {
	avion = new CAvion(p_avion);
	this->ecrireTempsDebut(p_temps);
}
vector<CPisteDecollage*> CEVAvionVeutDecoller::pistesDecollage = vector<CPisteDecollage*>();
void CEVAvionVeutDecoller::run() {
	
	for (unsigned int i = 0; i < pistesDecollage.size() && avion->lireEtat() == Etat::ATTENTE_PISTE; i++) {
		//Liste attente vide, on peut faire débarquer l'avion
		// ! Voir si possibilité de !
		if (pistesDecollage[i]->lireListeAttenteAvion().empty() && !pistesDecollage[i]->lireOccupation()) {
			avion->modifierEtat(Etat::DECOLLE);
			pistesDecollage[i]->modifierOccupation(true);
			std::cout << "Avion numero " << avion->lireIdAvion() << " se prepare au decollage sur la piste numero " << pistesDecollage[i]->lireIdPisteD() << std::endl;
			CEVAvionDecolle EVAD(*avion, pistesDecollage[i], this->lireTempsDebut());
			EVAD.run();
		}
		//Liste attente non vide, on fait décoller le premier avion de la queue
		else if (!pistesDecollage[i]->lireOccupation()) {

			pistesDecollage[i]->lireListeAttenteAvion().front()->modifierEtat(Etat::DECOLLE);
			pistesDecollage[i]->modifierOccupation(true);
			std::cout << "Avion numero "<<avion->lireIdAvion() << " se prepare au decollage sur la piste numero "<< pistesDecollage[i]->lireIdPisteD() << std::endl;
			CEVAvionDecolle EVAD(*(pistesDecollage[i]->lireListeAttenteAvion().front()), pistesDecollage[i], this->lireTempsDebut());
			EVAD.run();

		}
	}
}

