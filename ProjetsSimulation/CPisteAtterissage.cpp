#include "CPisteAtterissage.h"

CPisteAtterissage::CPisteAtterissage()
{
	idPisteA = 0;
}

CPisteAtterissage::CPisteAtterissage(CPisteAtterissage& p_pisteA)
{
	idPisteA = p_pisteA.lireIdPisteA();
}

CPisteAtterissage::~CPisteAtterissage()
{
}

void CPisteAtterissage::ecrireIdPisteA(unsigned int p_idPisteA)
{
	idPisteA = p_idPisteA;
}

unsigned int CPisteAtterissage::lireIdPisteA()
{
	return idPisteA;
}

void CPisteAtterissage::ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion)
{
	while (!p_listeAttenteAvion.empty()) {
		CAvion* avionTMP = new CAvion(*p_listeAttenteAvion.front());
		ListeAttenteAvion.push(avionTMP);
		p_listeAttenteAvion.pop();
	}
}

queue<CAvion*> CPisteAtterissage::lireListeAttenteAvion()
{
	return move(ListeAttenteAvion);
}
