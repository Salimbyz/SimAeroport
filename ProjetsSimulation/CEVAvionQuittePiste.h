/**
 * @file CEVAvionQuittePiste.h
 * @brief Définition de la classe CEVAvionQuittePiste.
 */

#pragma once

#include "CEvenement.h"

 /**
  * @class CEVAvionQuittePiste
  * @brief Classe représentant un événement d'un avion quittant une piste d'atterrissage.
  */
class CEVAvionQuittePiste : public CEvenement {
private:
    CPisteAtterissage* pisteAtterissage; ///< Pointeur vers la piste d'atterrissage associée à l'événement.
    CAvion* avion; ///< Pointeur vers l'avion associé à l'événement.

public:
    /**
     * @brief Constructeur par défaut de la classe CEVAvionQuittePiste.
     */
    CEVAvionQuittePiste();

    /**
     * @brief Destructeur de la classe CEVAvionQuittePiste.
     */
    ~CEVAvionQuittePiste();

    /**
     * @brief Constructeur de la classe CEVAvionQuittePiste avec des paramètres.
     * @param p_avion L'avion associé à l'événement.
     * @param p_pisteAtterrissage La piste d'atterrissage associée à l'événement.
     * @param p_time Temps de l'événement.
     */
    CEVAvionQuittePiste(CAvion p_avion, CPisteAtterissage* p_pisteAtterrissage, time_t p_time);

    /**
     * @brief Accesseur pour lire la piste d'atterrissage associée à l'événement.
     * @return La piste d'atterrissage.
     */
    CPisteAtterissage LirePisteAtterissage() { return *pisteAtterissage; }

    /**
     * @brief Mutateur pour modifier la piste d'atterrissage associée à l'événement.
     * @param p_pisteAtterissage La nouvelle piste d'atterrissage.
     */
    void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) { *pisteAtterissage = p_pisteAtterissage; }

    /**
     * @brief Accesseur pour lire l'avion associé à l'événement.
     * @return L'avion associé à l'événement.
     */
    CAvion LireAvion() { return *avion; }

    /**
     * @brief Mutateur pour modifier l'avion associé à l'événement.
     * @param p_avion Le nouvel avion.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief Méthode pour exécuter l'événement.
     */
    void run();
};
