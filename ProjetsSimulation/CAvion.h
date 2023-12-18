#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

enum class Etat {
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
	CAvion(unsigned int p_idAvion, time_t p_heureArriveePrevue, time_t heureDepartPrevue,Etat p_etat);
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

	void lireAvion();

	string enumToString(Etat value) {
		switch (value) {
		case Etat::EN_VOL:
			return "En vol";
		case Etat::ATTENTE_PORTE:
			return "Attente porte";
		case Etat::PARKING:
			return "Parking";
		case Etat::PORTE:
			return"Porte";
		case Etat::ATTENTE_PISTE:
			return "attente piste";
		case Etat::PARTI:
			return "Parti";
		default:
			return "Unknown";
		}
	}
};