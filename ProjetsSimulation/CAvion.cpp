#include "CAvion.h"

CAvion::CAvion()
{
	idAvion = 0;
	nbAvion = 0;
}

CAvion::CAvion(CAvion& p_avion)
{
	idAvion = p_avion.lireIdAvion();
	nbAvion = p_avion.lireNbAvion();
	heureArriveePrevue = time(NULL);
	heureDepartPrevue = time(NULL);
}

CAvion::~CAvion()
{
}

void CAvion::modifierIdAvion(int p_idAvion)
{
	idAvion = p_idAvion;
}

unsigned int CAvion::lireIdAvion()
{
	return idAvion;
}

void CAvion::modifierNbAvion(static int p_nbAvion)
{
	nbAvion = p_nbAvion;
}

int CAvion::lireNbAvion()
{
	return nbAvion;
}

void CAvion::modifierEtat(Etat p_etat)
{
	etat = p_etat;
}

Etat CAvion::lireEtat()
{
	return etat;
}
