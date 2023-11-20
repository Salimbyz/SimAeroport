#include "CPisteDecollage.h"

CPisteDecollage::CPisteDecollage(CPisteDecollage& p_pisteD)
{
	idPisteD = p_pisteD.lireIdPisteD();
	listeAttenteAvion = p_pisteD.lireListeAttenteAvion();
}

CPisteDecollage::~CPisteDecollage()
{
	while (!listeAttenteAvion.empty()) {
		delete listeAttenteAvion.front();
		listeAttenteAvion.pop();
	}
}

void CPisteDecollage::ecrireIdPisteD(unsigned int p_idPisteD)
{
	idPisteD = p_idPisteD;
}

unsigned int CPisteDecollage::lireIdPisteD()
{
	return idPisteD;
}

void CPisteDecollage::ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion)
{
	while (!p_listeAttenteAvion.empty()) {
		CAvion* avionTMP = new CAvion(*p_listeAttenteAvion.front());
		listeAttenteAvion.push(avionTMP);
		p_listeAttenteAvion.pop();
	}
}

queue<CAvion*> CPisteDecollage::lireListeAttenteAvion()
{
	return move(listeAttenteAvion);
}
