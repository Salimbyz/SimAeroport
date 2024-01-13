/**
 * @file CEVAvionQuittePiste.h
 * @brief D�finition de la classe CEVAvionQuittePiste.
 */

#pragma once

#include "CEvenement.h"

 /**
  * @class CEVAvionQuittePiste
  * @brief Classe repr�sentant un �v�nement d'un avion quittant une piste d'atterrissage.
  */
class CEVAvionQuittePiste : public CEvenement {
private:
    CPisteAtterissage* pisteAtterissage; ///< Pointeur vers la piste d'atterrissage associ�e � l'�v�nement.
    CAvion* avion; ///< Pointeur vers l'avion associ� � l'�v�nement.

public:
    /**
     * @brief Constructeur par d�faut de la classe CEVAvionQuittePiste.
     */
    CEVAvionQuittePiste();

    /**
     * @brief Destructeur de la classe CEVAvionQuittePiste.
     */
    ~CEVAvionQuittePiste();

    /**
     * @brief Constructeur de la classe CEVAvionQuittePiste avec des param�tres.
     * @param p_avion L'avion associ� � l'�v�nement.
     * @param p_pisteAtterrissage La piste d'atterrissage associ�e � l'�v�nement.
     * @param p_time Temps de l'�v�nement.
     */
    CEVAvionQuittePiste(CAvion p_avion, CPisteAtterissage* p_pisteAtterrissage, time_t p_time);

    /**
     * @brief Accesseur pour lire la piste d'atterrissage associ�e � l'�v�nement.
     * @return La piste d'atterrissage.
     */
    CPisteAtterissage LirePisteAtterissage() { return *pisteAtterissage; }

    /**
     * @brief Mutateur pour modifier la piste d'atterrissage associ�e � l'�v�nement.
     * @param p_pisteAtterissage La nouvelle piste d'atterrissage.
     */
    void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) { *pisteAtterissage = p_pisteAtterissage; }

    /**
     * @brief Accesseur pour lire l'avion associ� � l'�v�nement.
     * @return L'avion associ� � l'�v�nement.
     */
    CAvion LireAvion() { return *avion; }

    /**
     * @brief Mutateur pour modifier l'avion associ� � l'�v�nement.
     * @param p_avion Le nouvel avion.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief M�thode pour ex�cuter l'�v�nement.
     */
    void run();
};
