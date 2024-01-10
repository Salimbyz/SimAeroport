#include "CPisteDecollage.h"

queue<CAvion*> CPisteDecollage::listeAttenteAvion;

CPisteDecollage::CPisteDecollage(const CPisteDecollage& p_pisteD)
{
	idPisteD = p_pisteD.idPisteD;
}

CPisteDecollage::~CPisteDecollage()
{
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
	//Boucle tant que qui s'arr�tera une fois que la liste d'attente pass� en param�tre sera vid�
	while (!p_listeAttenteAvion.empty()) {
		CAvion* avionTMP = new CAvion(*p_listeAttenteAvion.front());// Cr�ation d'un objet CAvion temporaire correspondant au premier avion de la liste d'attente
		listeAttenteAvion.push(avionTMP);//Ajout de l'avion dans la liste attente de notre objet
		p_listeAttenteAvion.pop();//On supprime l'�l�ment r�cup�r� de la liste d'attente param�tre.
		delete avionTMP;//Destruction de l'avion temporaire
	}
}

queue<CAvion*> CPisteDecollage::lireListeAttenteAvion()
{
	return listeAttenteAvion;
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
