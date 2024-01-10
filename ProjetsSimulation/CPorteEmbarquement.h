#pragma once
#include <iostream>
#include<queue>
#include "CAvion.h"
#include "CRessource.h"

using namespace std;

/**
 * @class CPorteEmbarquement
 * @brief Classe repr�sentant une porte d'embarquement.
 *
 * Cette classe g�re les op�rations li�es � une porte d'embarquement, y compris la gestion des avions en attente � cette porte.
 */
class CPorteEmbarquement : public CRessource
{
private:
	unsigned int idPorteE;             ///< Identifiant unique de la porte d'embarquement.
	static queue<CAvion*> listeAttenteAvion; ///< File d'attente des avions � la porte d'embarquement.

public:
	/**
	 * @brief Constructeur par d�faut de CPorteEmbarquement.
	 */
	CPorteEmbarquement() :idPorteE(0) {};

	/**
	 * @brief Constructeur de copie de CPorteEmbarquement.
	 * @param p_porteE Objet CPorteEmbarquement � copier.
	 */
	CPorteEmbarquement(const CPorteEmbarquement& p_porteE);

	/**
	 * @brief Destructeur de CPorteEmbarquement.
	 */
	~CPorteEmbarquement();

	/**
	 * @brief Modifie l'identifiant de la porte d'embarquement.
	 * @param p_idPorteE Nouvel identifiant de la porte.
	 */
	void ecrireIdPorteE(unsigned int p_idPorteE);

	/**
	 * @brief Retourne l'identifiant de la porte d'embarquement.
	 * @return Identifiant de la porte.
	 */
	unsigned int lireIdPorteE();

	/**
	 * @brief Modifie la liste d'attente des avions pour la porte d'embarquement.
	 * @param p_listeAttenteAvion Nouvelle liste d'attente des avions.
	 */
	static void ecrireListeAttenteAvion(queue<CAvion*> p_listeAttenteAvion);

	/**
	 * @brief Retourne la liste d'attente des avions pour la porte d'embarquement.
	 * @return File d'attente des avions.
	 */
	static queue<CAvion*> lireListeAttenteAvion();

	/**
	 * @brief Ajoute un avion � la liste d'attente de la porte d'embarquement.
	 * @param p_avionAjout Pointeur vers l'avion � ajouter � la liste d'attente.
	 */
	void ajouterAvionListeA(CAvion* p_avionAjout);

	/**
	 * @brief Retire le premier avion de la liste d'attente de la porte d'embarquement.
	 */
	void retirerAvionListeA();

	/**
	 * @brief Affiche les informations de la piste d'atterrissage.
	 */
	void lirePorteEmbarquement();
};
