/**
 * @file CEVAvionVaGate.h
 * @brief Définition de la classe CEVAvionVaGate.
 */

#pragma once

#include "CEvenement.h"
#include "CPorteEmbarquement.h"

 /**
  * @class CEVAvionVaGate
  * @brief Classe représentant un événement d'un avion se dirigeant vers une porte d'embarquement.
  */
class CEVAvionVaGate : public CEvenement {
private:
    CAvion* avion; ///< Pointeur vers l'avion associé à l'événement.
    CPorteEmbarquement* gate; ///< Pointeur vers la porte d'embarquement associée à l'événement.

public:
    /**
     * @brief Constructeur par défaut de la classe CEVAvionVaGate.
     */
    CEVAvionVaGate();

    /**
     * @brief Constructeur de la classe CEVAvionVaGate avec des paramètres.
     * @param p_avion L'avion associé à l'événement.
     * @param p_porte La porte d'embarquement associée à l'événement.
     * @param p_temps Temps de l'événement.
     */
    CEVAvionVaGate(CAvion p_avion, CPorteEmbarquement* p_porte, time_t p_temps);

    /**
     * @brief Destructeur de la classe CEVAvionVaGate.
     */
    ~CEVAvionVaGate();

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
     * @brief Accesseur pour lire la porte d'embarquement associée à l'événement.
     * @return La porte d'embarquement associée à l'événement.
     */
    CPorteEmbarquement LirePisteAtterrissage() { return *gate; }

    /**
     * @brief Mutateur pour modifier la porte d'embarquement associée à l'événement.
     * @param p_gate La nouvelle porte d'embarquement.
     */
    void ModifierGate(CPorteEmbarquement p_gate) { *gate = p_gate; }

    /**
     * @brief Méthode pour exécuter l'événement.
     */
    void run();
};
