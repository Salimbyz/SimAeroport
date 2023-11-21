#include "CPisteAtterissage.h"

CPisteAtterissage::CPisteAtterissage(CPisteAtterissage& p_pisteA)
{
	idPisteA = p_pisteA.lireIdPisteA();
	listeAttenteAvion = p_pisteA.lireListeAttenteAvion();
}

CPisteAtterissage::~CPisteAtterissage()
{
	while (!listeAttenteAvion.empty()) {
		delete listeAttenteAvion.front();
		listeAttenteAvion.pop();
	}
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
		listeAttenteAvion.push(avionTMP);
		p_listeAttenteAvion.pop();
	}
}

queue<CAvion*> CPisteAtterissage::lireListeAttenteAvion()
{
	return move(listeAttenteAvion);
}

void CPisteAtterissage::ajouterAvionListeA(CAvion* p_avionAjout)
{
	listeAttenteAvion.push(p_avionAjout);
}

void CPisteAtterissage::retirerAvionListeA()
{
	listeAttenteAvion.pop();
}

void CPisteAtterissage::lirePisteAtterissage()
{
	queue<CAvion*> temp;
	while (!listeAttenteAvion.empty()) {
		CAvion* AvionTemp = listeAttenteAvion.front();
		temp.push(AvionTemp);
		listeAttenteAvion.pop();
	}
	cout << idPisteA << endl;
	while (!temp.empty()) {
		temp.front()->lireAvion();
		cout << endl;
		temp.pop();
	}
	while (!temp.empty()) {
		delete temp.front();
		temp.pop();
	}
}
