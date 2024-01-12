#include "CAvion.h"

CAvion::CAvion()
{
	idAvion = 0;
	heureArriveePrevue = 0;
	heureDepartPrevue = 0;
	etat = Etat::EN_VOL; //De base un avion est considéré en vol.
}

CAvion::CAvion(unsigned int p_idAvion, time_t p_heureArriveePrevue, time_t p_heureDepartPrevue, Etat p_etat)
{
	idAvion = p_idAvion;
	heureArriveePrevue = p_heureArriveePrevue;
	heureDepartPrevue = p_heureDepartPrevue;
	etat = p_etat;
}

CAvion::CAvion(const CAvion& p_avion)
{
	idAvion = p_avion.idAvion;
	heureArriveePrevue = p_avion.heureArriveePrevue;
	heureDepartPrevue = p_avion.heureDepartPrevue;
	etat = p_avion.etat;
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

void CAvion::modifierEtat(Etat p_etat)
{
	etat = p_etat;
}

Etat CAvion::lireEtat()
{
	return etat;
}

void CAvion::modifierHeureArriveePrevue(time_t p_heureArriveePrevue)
{
	heureArriveePrevue = p_heureArriveePrevue;
}

time_t CAvion::lireHeureArriveePrevue()
{
	return heureArriveePrevue;
}

void CAvion::modifierHeureDepartPrevue(time_t p_heureDepartPrevue)
{
	heureDepartPrevue = p_heureDepartPrevue;
}
time_t CAvion::lireHeureDepartPrevue()
{
	return heureDepartPrevue;
}

