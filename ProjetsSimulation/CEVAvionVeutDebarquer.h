/**
 * @file CEVAvionVeutDebarquer.h
 * @brief Définition de la classe CEVAvionVeutDebarquer.
 */

#pragma once

#include "CEvenement.h"

 /**
  * @class CEVAvionVeutDebarquer
  * @brief Classe représentant un événement d'un avion souhaitant débarquer.
  *
  * Cette classe dérive de CEvenement et gère les événements d'avions
  * souhaitant débarquer à une porte d'embarquement
  */

class CEVAvionVeutDebarquer : public CEvenement {
private:
    CAvion* avion; ///< Pointeur vers l'avion associé à l'événement.
    static std::vector<CPorteEmbarquement*> gates; ///< Liste statique des portes d'embarquement.

public:
    /**
     * @brief Constructeur par défaut de la classe CEVAvionVeutDebarquer.
     */
    CEVAvionVeutDebarquer();

    /**
     * @brief Constructeur de la classe CEVAvionVeutDebarquer avec des paramètres.
     * @param p_avion L'avion associé à l'événement.
     * @param p_temps Temps de l'événement.
     */
    CEVAvionVeutDebarquer(CAvion p_avion, time_t p_temps);

    /**
     * @brief Destructeur de la classe CEVAvionVeutDebarquer.
     */
    ~CEVAvionVeutDebarquer();

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
     * @brief Retourne la liste des portes d'embarquement.
     * @return La liste des portes d'embarquement.
     */
    static std::vector<CPorteEmbarquement*> LireGates() { return gates; }

    /**
     * @brief Ajoute une porte d'embarquement à la liste statique.
     * @param p_gate La porte d'embarquement à ajouter.
     */
    static void AjouterGate(CPorteEmbarquement p_gate){
        CPorteEmbarquement* porteE = new CPorteEmbarquement(p_gate);
        gates.push_back(porteE);
    }


    /**
     * @brief Exécute l'événement.
     */
    void run();
};
