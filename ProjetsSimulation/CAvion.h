#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

enum class Etat {
	EN_VOL,
	ATTERRIT,
	ATTENTE_PORTE,
	PARKING,
	PORTE,
	ATTENTE_PISTE,
	DECOLLE,
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
	CAvion(unsigned int p_idAvion, time_t p_heureArriveePrevue, time_t heureDepartPrevue, Etat p_etat);
	CAvion(const CAvion& p_avion);
	~CAvion();

	void modifierIdAvion(int p_idAvion);
	unsigned int lireIdAvion();

	void modifierEtat(Etat p_etat);
	Etat lireEtat();

	void modifierHeureArriveePrevue(time_t p_heureArriveePrevue);
	time_t lireHeureArriveePrevue();

	void modifierHeureDepartPrevue(time_t p_heureDepartPrevue);
	time_t lireHeureDepartPrevue();

	/**
	* @fn lireAvion()
	* @brief Constrcuteur par recopie de la classe CGraphe
	*
	* @
	*/
	void lireAvion();

	static string enumToString(Etat value) {
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
		case Etat::ATTERRIT:
			return "Atterrit";
		case Etat::DECOLLE:
			return "Décolle";
		default:
			return "Unknown";
		}
	}

	static Etat stringToEnum(string str) {
		if (str == "En vol") return Etat::EN_VOL;
		if (str == "Attente porte") return Etat::ATTENTE_PORTE;
		if (str == "Parking") return Etat::PARKING;
		if (str == "Porte") return Etat::PORTE;
		if (str == "Attente piste") return Etat::ATTENTE_PISTE;
		if (str == "Parti") return Etat::PARTI;
		if (str == "Atterrit") return Etat::ATTERRIT;
		if (str == "Décolle") return Etat::DECOLLE;
		else throw std::invalid_argument("chaine de caractère invalide");
	}
};