#pragma once
#include <iostream>
#include <time.h>
#include <queue>
#include "CAvion.h"
#include "CRessource.h"

using namespace std;

/**
 * @class CPisteAtterissage
 * @brief Classe représentant une piste d'atterrissage.
 *
 * Cette classe gère les opérations liées à une piste d'atterrissage, y compris la gestion des avions en attente d'atterrissage.
 */
class CPisteAtterissage : public CRessource
{
private:
	unsigned int idPisteA;             ///< Identifiant unique de la piste d'atterrissage.
	static queue<CAvion*> listeAttenteAvion; ///< File d'attente des avions en attente d'atterrissage.

public:
	/**
	 * @brief Constructeur par défaut de CPisteAtterissage.
	 */
	CPisteAtterissage() :idPisteA(0) {};

	/**
	 * @brief Constructeur de copie de CPisteAtterissage.
	 * @param p_pisteA Objet CPisteAtterissage à copier.
	 */
	CPisteAtterissage(const CPisteAtterissage& p_pisteA);

	/**
	 * @brief Constructeur de CPisteAtterissage avec un identifiant spécifique.
	 * @param p_id Identifiant de la piste d'atterrissage.
	 */
	CPisteAtterissage(unsigned int p_id);

	/**
	 * @brief Destructeur de CPisteAtterissage.
	 */
	~CPisteAtterissage();

	/**
	 * @brief Modifie l'identifiant de la piste d'atterrissage.
	 * @param p_idPisteA Nouvel identifiant de la piste.
	 */
	void ecrireIdPisteA(unsigned int p_idPisteA);

	/**
	 * @brief Retourne l'identifiant de la piste d'atterrissage.
	 * @return Identifiant de la piste.
	 */
	unsigned int lireIdPisteA();

	/**
	 * @brief Modifie la liste d'attente des avions pour la piste d'atterrissage.
	 * @param p_listeAttenteAvion Nouvelle liste d'attente des avions.
	 */
	static void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);

	/**
	 * @brief Retourne la liste d'attente des avions pour la piste d'atterrissage.
	 * @return File d'attente des avions.
	 */
	static queue<CAvion*> lireListeAttenteAvion();

	/**
	 * @brief Ajoute un avion à la liste d'attente de la piste d'atterrissage.
	 * @param p_avionAjout Pointeur vers l'avion à ajouter à la liste d'attente.
	 */
	void ajouterAvionListeA(CAvion* p_avionAjout);

	/**
	 * @brief Retire le premier avion de la liste d'attente de la piste d'atterrissage.
	 */
	void retirerAvionListeA();
};
