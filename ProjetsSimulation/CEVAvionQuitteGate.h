#pragma once
#include "CEvenement.h"
#include "CPorteEmbarquement.h"

/**
 * @class CEVAvionQuitteGate
 * @brief Classe repr�sentant l'�v�nement o� un avion quitte la porte d'embarquement (gate).
 *
 * Cette classe g�re les �v�nements li�s au d�part d'un avion depuis la porte d'embarquement.
 * Elle conserve les informations sur l'avion et la porte d'embarquement concern�s.
 */
class CEVAvionQuitteGate :
    public CEvenement
{
private:
    CPorteEmbarquement* gate; ///< Pointeur sur la porte d'embarquement utilis�e par l'avion.
    CAvion* avion; ///< Pointeur sur l'avion qui quitte la porte d'embarquement.
public :
    /**
     * @brief Constructeur par d�faut.
     */
    CEVAvionQuitteGate();

    /**
     * @brief Constructeur avec param�tres.
     *
     * @param p_avion Avion qui quitte la porte d'embarquement.
     * @param p_gate Pointeur sur la porte d'embarquement.
     * @param p_temps Temps de l'�v�nement.
     */
    CEVAvionQuitteGate(CAvion p_avion, CPorteEmbarquement* p_gate, time_t p_temps);

    /**
     * @brief Destructeur.
     */
    ~CEVAvionQuitteGate();

    /**
     * @brief Retourne l'avion concern� par l'�v�nement.
     *
     * @return CAvion L'avion qui quitte la porte d'embarquement.
     */
    CAvion LireAvion() { return *avion; }
    
    /**
     * @brief Modifie l'avion concern� par l'�v�nement.
     *
     * @param p_avion Avion qui quitte la porte d'embarquement.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief Retourne la porte d'embarquement.
     *
     * @return CPorteEmbarquement La porte d'embarquement utilis�e par l'avion.
     */
    CPorteEmbarquement LireGate() { return *gate; }
    
    /**
     * @brief Modifie la porte d'embarquement.
     *
     * @param p_gate Nouvelle porte d'embarquement.
     */
    void ModifierPorteEmbarquement(CPorteEmbarquement p_gate) { *gate = p_gate; }

    /**
     * @brief Ex�cute l'�v�nement de d�part de l'avion de la porte d'embarquement.
     */
    void run();

    
};

