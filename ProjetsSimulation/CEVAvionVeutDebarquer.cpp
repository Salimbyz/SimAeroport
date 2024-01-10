#include "CEVAvionVeutDebarquer.h"
#include "CEVAvionVaGate.h"
CEVAvionVeutDebarquer::CEVAvionVeutDebarquer()
{
	avion = new CAvion();
}

CEVAvionVeutDebarquer::CEVAvionVeutDebarquer(CAvion p_avion, time_t p_temps)
{
	//A modifier avec 
	avion = new CAvion(p_avion);
	avion->modifierEtat(avion->stringToEnum("ATTENTE_PORTE"));
	this->ecrireTempsDebut(p_temps);
}

CEVAvionVeutDebarquer::~CEVAvionVeutDebarquer()
{
	delete(avion);
}
vector<CPorteEmbarquement> CEVAvionVeutDebarquer::gates = vector<CPorteEmbarquement>();
void CEVAvionVeutDebarquer::run()
{
	
	for (int i = 0; i < gates.size() && avion->lireEtat() == Etat::ATTENTE_PORTE; i++) {
		//Liste attente vide, on peut faire d�barquer l'avion
		// ! Voir si possibilit� de !
		if (gates[i].lireListeAttenteAvion().empty() && !gates[i].lireOccupation()) {
			avion->modifierEtat(Etat::PORTE);
			gates[i].modifierOccupation(true);
			CEVAvionVaGate EVAVG(*avion, gates[i],this->lireTempsDebut());
			EVAVG.run();
		}
		//Liste attente non vide, on fait d�coller le premier avion de la queue
		else if (!gates[i].lireOccupation()) {
			
			gates[i].lireListeAttenteAvion().front()->modifierEtat(Etat::PORTE);
			gates[i].modifierOccupation(true);
			CEVAvionVaGate EVAVG(*(gates[i].lireListeAttenteAvion().front()), gates[i], this->lireTempsDebut());
			EVAVG.run();

		}
		//La liste d'attente est actualis�e � la sortie de chaque avion
	}
}
