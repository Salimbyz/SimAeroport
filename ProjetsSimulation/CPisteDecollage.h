#pragma once
#include <iostream>
#include <queue>
#include "CAvion.h"
#include "CRessource.h"

using namespace std;

/**
 * @class CPisteDecollage
 * @brief Classe repr�sentant une piste de d�collage.
 *
 * Cette classe g�re les op�rations li�es � une piste de d�collage, y compris la gestion des avions en attente de d�collage.
 */
class CPisteDecollage : public CRessource
{
private:
	unsigned int idPisteD;             ///< Identifiant unique de la piste de d�collage.
	static queue<CAvion*> listeAttenteAvion; ///< File d'attente des avions en attente de d�collage.

public:
	/**
	 * @brief Constructeur par d�faut de CPisteDecollage.
	 */
	CPisteDecollage() :idPisteD(0) {};

	/**
	 * @brief Constructeur de copie de CPisteDecollage.
	 * @param p_pisteD Objet CPisteDecollage � copier.
	 */
	CPisteDecollage(const CPisteDecollage& p_pisteD);

	/**
	 * @brief Destructeur de CPisteDecollage.
	 */
	~CPisteDecollage();

	/**
	 * @brief Modifie l'identifiant de la piste de d�collage.
	 * @param p_idPisteD Nouvel identifiant de la piste.
	 */
	void ecrireIdPisteD(unsigned int p_idPisteD);

	/**
	 * @brief Retourne l'identifiant de la piste de d�collage.
	 * @return Identifiant de la piste.
	 */
	unsigned int lireIdPisteD();

	/**
	 * @brief Modifie la liste d'attente des avions pour la piste de d�collage.
	 * @param p_listeAttenteAvion Nouvelle liste d'attente des avions.
	 */
	static void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);

	/**
	 * @brief Retourne la liste d'attente des avions pour la piste de d�collage.
	 * @return File d'attente des avions.
	 */
	static queue<CAvion*> lireListeAttenteAvion();

	/**
	 * @brief Ajoute un avion � la liste d'attente de la piste de d�collage.
	 * @param p_avionAjout Pointeur vers l'avion � ajouter � la liste d'attente.
	 */
	void ajouterAvionListeA(CAvion* p_avionAjout);

	/**
	 * @brief Retire le premier avion de la liste d'attente de la piste de d�collage.
	 */
	void retirerAvionListeA();

	/**
	 * @brief Affiche les informations de la piste d'atterrissage.
	 */
	void lirePisteAtterissage();
};
