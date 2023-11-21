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

void CPisteDecollage::lirePisteAtterissage()
{
	queue<CAvion*> temp;
	while (!listeAttenteAvion.empty()) {
		CAvion* AvionTemp = listeAttenteAvion.front();
		temp.push(AvionTemp);
		listeAttenteAvion.pop();
	}
	cout << idPisteD << endl;
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

void CPisteDecollage::ajouterAvionListeA(CAvion* p_avionAjout)
{
	listeAttenteAvion.push(p_avionAjout);
}

void CPisteDecollage::retirerAvionListeA()
{
	listeAttenteAvion.pop();
}
