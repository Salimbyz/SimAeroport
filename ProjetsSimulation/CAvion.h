#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

/**
 * @enum Etat
 * @brief �num�ration des diff�rents �tats possibles d'un avion.
 */
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

/**
 * @class CAvion
 * @brief Classe repr�sentant un avion.
 *
 * Cette classe g�re les informations et les op�rations li�es � un avion.
 */
class CAvion
{
private:
	unsigned int idAvion;             ///< Identifiant unique de l'avion.
	time_t heureArriveePrevue;        ///< Heure d'arriv�e pr�vue de l'avion.
	time_t heureDepartPrevue;         ///< Heure de d�part pr�vue de l'avion.
	Etat etat;                        ///< �tat actuel de l'avion.

public:
	/**
	 * @brief Constructeur par d�faut de CAvion.
	 */
	CAvion();

	/**
	 * @brief Constructeur de CAvion avec param�tres.
	 * @param p_idAvion Identifiant de l'avion.
	 * @param p_heureArriveePrevue Heure d'arriv�e pr�vue de l'avion.
	 * @param heureDepartPrevue Heure de d�part pr�vue de l'avion.
	 * @param p_etat �tat initial de l'avion.
	 */
	CAvion(unsigned int p_idAvion, time_t p_heureArriveePrevue, time_t heureDepartPrevue, Etat p_etat);

	/**
	 * @brief Constructeur de copie de CAvion.
	 * @param p_avion Objet CAvion � copier.
	 */
	CAvion(const CAvion& p_avion);

	/**
	 * @brief Destructeur de CAvion.
	 */
	~CAvion();

	/**
	 * @brief Modifie l'identifiant de l'avion.
	 * @param p_idAvion Nouvel identifiant de l'avion.
	 */
	void modifierIdAvion(int p_idAvion);

	/**
	 * @brief Retourne l'identifiant de l'avion.
	 * @return Identifiant de l'avion.
	 */
	unsigned int lireIdAvion();

	/**
	 * @brief Modifie l'�tat de l'avion.
	 * @param p_etat Nouvel �tat de l'avion.
	 */
	void modifierEtat(Etat p_etat);

	/**
	 * @brief Retourne l'�tat actuel de l'avion.
	 * @return �tat actuel de l'avion.
	 */
	Etat lireEtat();

	/**
	 * @brief Modifie l'heure d'arriv�e pr�vue de l'avion.
	 * @param p_heureArriveePrevue Nouvelle heure d'arriv�e pr�vue.
	 */
	void modifierHeureArriveePrevue(time_t p_heureArriveePrevue);

	/**
	 * @brief Retourne l'heure d'arriv�e pr�vue de l'avion.
	 * @return Heure d'arriv�e pr�vue.
	 */
	time_t lireHeureArriveePrevue();

	/**
	 * @brief Modifie l'heure de d�part pr�vue de l'avion.
	 * @param p_heureDepartPrevue Nouvelle heure de d�part pr�vue.
	 */
	void modifierHeureDepartPrevue(time_t p_heureDepartPrevue);

	/**
	 * @brief Retourne l'heure de d�part pr�vue de l'avion.
	 * @return Heure de d�part pr�vue.
	 */
	time_t lireHeureDepartPrevue();

	/**
	 * @brief Affiche les informations de l'avion.
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
			return "D�colle";
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
		if (str == "D�colle") return Etat::DECOLLE;
		else throw std::invalid_argument("chaine de caract�re invalide");
	}
};