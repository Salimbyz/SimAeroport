#pragma once
#include <iostream>
#include <stdio.h>
#include "CAvion.h"

/**
 * @class CRessource
 * @brief Classe représentant une ressource générale (pouvant être une piste, une porte, etc.).
 *
 * Cette classe sert de base pour différentes ressources dans un aéroport, telles que les pistes d'atterrissage, de décollage ou les portes d'embarquement.
 */
class CRessource
{
private:
	bool occupe; ///< Indique si la ressource est actuellement occupée.

public:
	/**
	 * @brief Constructeur par défaut de CRessource.
	 */
	CRessource();

	/**
	 * @brief Constructeur de copie de CRessource.
	 * @param p_ressource Objet CRessource à copier.
	 */
	CRessource(const CRessource& p_ressource);

	/**
	 * @brief Constructeur de CRessource avec état d'occupation.
	 * @param p_occupe État initial d'occupation de la ressource.
	 */
	CRessource(bool p_occupe);

	/**
	 * @brief Destructeur de CRessource.
	 */
	~CRessource();

	/**
	 * @brief Modifie l'état d'occupation de la ressource.
	 * @param p_occupe Nouvel état d'occupation.
	 */
	void modifierOccupation(bool p_occupe);

	/**
	 * @brief Retourne l'état d'occupation de la ressource.
	 * @return État d'occupation actuel.
	 */
	bool lireOccupation();
};
