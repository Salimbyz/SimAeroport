#include "CEVAvionQuitteGate.h"
#include "CEVAvionVeutDecoller.h"
#include "CEVAvionVaGate.h"
#include "CEVAvionVeutDebarquer.h"
CEVAvionQuitteGate::CEVAvionQuitteGate()
{
	avion = new CAvion();
	gate = new CPorteEmbarquement();
}

CEVAvionQuitteGate::CEVAvionQuitteGate(CAvion p_avion, CPorteEmbarquement* p_gate, time_t p_temps)
{
	avion = new CAvion(p_avion);
	gate = p_gate;
	this->ecrireTempsDebut(p_temps);
}

CEVAvionQuitteGate::~CEVAvionQuitteGate()
{
	delete(avion);
}

void CEVAvionQuitteGate::run()
{
	std::cout << "Avion " << avion->lireIdAvion() << " quitte la porte numero " << gate->lireIdPorteE() << std::endl;
	avion->modifierEtat(Etat::ATTENTE_PISTE);
	gate->modifierOccupation(false);
	//L'avion reste une demi heure a la porte d'embarquement, apres la fin de l'embarquement avant de vouloir decoller
	CEVAvionVeutDecoller EVAVD(*avion, this->lireTempsDebut()+1800);
	EVAVD.run();
	if (!gate->lireListeAttenteAvion().empty()) {
		*avion = *CPorteEmbarquement::lireListeAttenteAvion().front();
		CEVAvionVaGate AVG(*avion, gate, this->lireTempsDebut() + 144000);
		AVG.run();
		gate->retirerAvionListeA();
		/*
		if((difftime(this->lireTempsDebut(), avion->lireHeureArriveePrevue()) < 300)&&(this->lireTempsDebut()<avion->lireHeureArriveePrevue())){
			*avion = *CPorteEmbarquement::lireListeAttenteAvion().front();
			CEVAvionVaGate AVG(*avion, gate, this->lireTempsDebut() + 144000);
			AVG.run();
			gate->retirerAvionListeA();
		}
		else{
			*avion = *CPorteEmbarquement::lireListeAttenteAvion().front();
			CEVAvionVaGate AVG(*avion, gate, this->lireTempsDebut() + 144000);
			AVG.run();
			gate->retirerAvionListeA();
		}
		*/

	}



		

	
}
