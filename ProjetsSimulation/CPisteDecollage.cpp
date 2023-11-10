#include "CPisteDecollage.h"

CPisteDecollage::CPisteDecollage()
{
	idPisteD = 0;
}

CPisteDecollage::CPisteDecollage(CPisteDecollage& p_pisteD)
{
	idPisteD = p_pisteD.lireIdPisteD();
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
}

queue<CAvion*> CPisteDecollage::lireListeAttenteAvion()
{
	return queue<CAvion*>();
}
