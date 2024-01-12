#pragma once
#include "CEvenement.h"
#include "CPorteEmbarquement.h"

/**
 * @class CEVAvionQuitteGate
 * @brief Classe représentant l'événement où un avion quitte la porte d'embarquement (gate).
 *
 * Cette classe gère les événements liés au départ d'un avion depuis la porte d'embarquement.
 * Elle conserve les informations sur l'avion et la porte d'embarquement concernés.
 */
class CEVAvionQuitteGate :
    public CEvenement
{
private:
    CPorteEmbarquement* gate; ///< Pointeur sur la porte d'embarquement utilisée par l'avion.
    CAvion* avion; ///< Pointeur sur l'avion qui quitte la porte d'embarquement.
public :
    /**
     * @brief Constructeur par défaut.
     */
    CEVAvionQuitteGate();

    /**
     * @brief Constructeur avec paramètres.
     *
     * @param p_avion Avion qui quitte la porte d'embarquement.
     * @param p_gate Pointeur sur la porte d'embarquement.
     * @param p_temps Temps de l'événement.
     */
    CEVAvionQuitteGate(CAvion p_avion, CPorteEmbarquement* p_gate, time_t p_temps);

    /**
     * @brief Destructeur.
     */
    ~CEVAvionQuitteGate();

    /**
     * @brief Retourne l'avion concerné par l'événement.
     *
     * @return CAvion L'avion qui quitte la porte d'embarquement.
     */
    CAvion LireAvion() { return *avion; }
    
    /**
     * @brief Modifie l'avion concerné par l'événement.
     *
     * @param p_avion Avion qui quitte la porte d'embarquement.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief Retourne la porte d'embarquement.
     *
     * @return CPorteEmbarquement La porte d'embarquement utilisée par l'avion.
     */
    CPorteEmbarquement LireGate() { return *gate; }
    
    /**
     * @brief Modifie la porte d'embarquement.
     *
     * @param p_gate Nouvelle porte d'embarquement.
     */
    void ModifierPorteEmbarquement(CPorteEmbarquement p_gate) { *gate = p_gate; }

    /**
     * @brief Exécute l'événement de départ de l'avion de la porte d'embarquement.
     */
    void run();

    
};

