#include "CEVAvionVeutDebarquer.h"

CEVAvionVeutDebarquer::CEVAvionVeutDebarquer()
{
	avion = new CAvion();
	gates = vector<CPorteEmbarquement*>();
}

CEVAvionVeutDebarquer::CEVAvionVeutDebarquer(CAvion p_avion, vector<CPorteEmbarquement> p_gates, time_t p_temps)
{
	avion = new CAvion(p_avion);
	avion->modifierEtat(avion->stringToEnum("ATTENTE_PORTE"));
	gates.resize(p_gates.size());
	for (int i = 0; i < gates.size(); i++) {
		*gates[i] = p_gates[i];
	}
	this->ecrireTempsDebut(p_temps);
}

CEVAvionVeutDebarquer::~CEVAvionVeutDebarquer()
{
	delete(avion);
	for (int i = 0; i < gates.size(); i++) {
		delete(gates[i]);
	}
	gates.clear();
}

void CEVAvionVeutDebarquer::run()
{
	
	for (int i = 0; i < gates.size() && avion->enumToString(avion->lireEtat()) == "ATTENTE_PORTE"; i++) {
		//Liste attente vide, on peut faire débarquer l'avion
		// ! Voir si possibilité de !
		if (gates[i]->lireListeAttenteAvion().empty() && !gates[i]->lireOccupation()) {
			
		}
		//Liste attente non vide, on fait décoller le premier avion de la queue
		else if (!gates[i]->lireListeAttenteAvion().empty()) {

		}
		//La liste d'attente est actualisée à la sortie de chaque avion
	}
}
