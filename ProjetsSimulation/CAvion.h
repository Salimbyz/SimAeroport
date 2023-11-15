#pragma once
#include <iostream>
#include <time.h>

enum Etat {
	EN_VOL,
	ATTENTE_PORTE,
	PARKING,
	PORTE,
	ATTENTE_PISTE,
	PARTI
};

class CAvion
{
private:
	unsigned int idAvion;
	time_t heureArriveePrevue;
	time_t heureDepartPrevue;
	Etat etat;
public:

	CAvion();
	CAvion(CAvion& p_avion);
	~CAvion();

	void modifierIdAvion(int p_idAvion);
	unsigned int lireIdAvion();

	void modifierEtat(Etat p_etat);
	Etat lireEtat();

	void modifierHeureArriveePrevue(time_t p_heureArriveePrevue);
	time_t lireHeureArriveePrevue();

	void modifierHeureDepartPrevue(time_t p_heureDepartPrevue);
	time_t lireHeureDepartPrevue();

};