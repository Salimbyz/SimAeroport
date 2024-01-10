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
vector<CPisteDecollage> CEVAvionVeutDecoller::pistesDecollage = vector<CPisteDecollage>();
void CEVAvionVeutDecoller::run() {
	for (int i = 0; i < pistesDecollage.size() && avion->lireEtat() == Etat::ATTENTE_PORTE; i++) {
		//Liste attente vide, on peut faire d�barquer l'avion
		// ! Voir si possibilit� de !
		if (pistesDecollage[i].lireListeAttenteAvion().empty() && !pistesDecollage[i].lireOccupation()) {
			avion->modifierEtat(Etat::PORTE);
			pistesDecollage[i].modifierOccupation(true);
			std::cout << "L'avion numero " << avion->lireIdAvion() << " se prepare au decollage sur la piste numero " << pistesDecollage[i].lireIdPisteD();
			CEVAvionDecolle EVAD(*avion, pistesDecollage[i], this->lireTempsDebut());
			EVAD.run();
		}
		//Liste attente non vide, on fait d�coller le premier avion de la queue
		else if (!pistesDecollage[i].lireOccupation()) {

			pistesDecollage[i].lireListeAttenteAvion().front()->modifierEtat(Etat::PORTE);
			pistesDecollage[i].modifierOccupation(true);
			std::cout << "L'avion numero "<<avion->lireIdAvion() << " se prepare au decollage sur la piste numero "<< pistesDecollage[i].lireIdPisteD();
			CEVAvionDecolle EVAD(*(pistesDecollage[i].lireListeAttenteAvion().front()), pistesDecollage[i], this->lireTempsDebut());
			EVAD.run();

		}
	}
}

