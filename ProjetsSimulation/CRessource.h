#pragma once
#include <iostream>
#include <stdio.h>
#include "CAvion.h"

/**
 * @class CRessource
 * @brief Classe repr�sentant une ressource g�n�rale (pouvant �tre une piste, une porte, etc.).
 *
 * Cette classe sert de base pour diff�rentes ressources dans un a�roport, telles que les pistes d'atterrissage, de d�collage ou les portes d'embarquement.
 */
class CRessource
{
private:
	bool occupe; ///< Indique si la ressource est actuellement occup�e.

public:
	/**
	 * @brief Constructeur par d�faut de CRessource.
	 */
	CRessource();

	/**
	 * @brief Constructeur de copie de CRessource.
	 * @param p_ressource Objet CRessource � copier.
	 */
	CRessource(const CRessource& p_ressource);

	/**
	 * @brief Constructeur de CRessource avec �tat d'occupation.
	 * @param p_occupe �tat initial d'occupation de la ressource.
	 */
	CRessource(bool p_occupe);

	/**
	 * @brief Destructeur de CRessource.
	 */
	~CRessource();

	/**
	 * @brief Modifie l'�tat d'occupation de la ressource.
	 * @param p_occupe Nouvel �tat d'occupation.
	 */
	void modifierOccupation(bool p_occupe);

	/**
	 * @brief Retourne l'�tat d'occupation de la ressource.
	 * @return �tat d'occupation actuel.
	 */
	bool lireOccupation();
};
