/**
 * @file CEVAvionVaGate.h
 * @brief D�finition de la classe CEVAvionVaGate.
 */

#pragma once

#include "CEvenement.h"
#include "CPorteEmbarquement.h"

 /**
  * @class CEVAvionVaGate
  * @brief Classe repr�sentant un �v�nement d'un avion se dirigeant vers une porte d'embarquement.
  */
class CEVAvionVaGate : public CEvenement {
private:
    CAvion* avion; ///< Pointeur vers l'avion associ� � l'�v�nement.
    CPorteEmbarquement* gate; ///< Pointeur vers la porte d'embarquement associ�e � l'�v�nement.

public:
    /**
     * @brief Constructeur par d�faut de la classe CEVAvionVaGate.
     */
    CEVAvionVaGate();

    /**
     * @brief Constructeur de la classe CEVAvionVaGate avec des param�tres.
     * @param p_avion L'avion associ� � l'�v�nement.
     * @param p_porte La porte d'embarquement associ�e � l'�v�nement.
     * @param p_temps Temps de l'�v�nement.
     */
    CEVAvionVaGate(CAvion p_avion, CPorteEmbarquement* p_porte, time_t p_temps);

    /**
     * @brief Destructeur de la classe CEVAvionVaGate.
     */
    ~CEVAvionVaGate();

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
     * @brief Accesseur pour lire la porte d'embarquement associ�e � l'�v�nement.
     * @return La porte d'embarquement associ�e � l'�v�nement.
     */
    CPorteEmbarquement LirePisteAtterrissage() { return *gate; }

    /**
     * @brief Mutateur pour modifier la porte d'embarquement associ�e � l'�v�nement.
     * @param p_gate La nouvelle porte d'embarquement.
     */
    void ModifierGate(CPorteEmbarquement p_gate) { *gate = p_gate; }

    /**
     * @brief M�thode pour ex�cuter l'�v�nement.
     */
    void run();
};
