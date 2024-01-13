/**
 * @file CEVAvionVeutDebarquer.h
 * @brief D�finition de la classe CEVAvionVeutDebarquer.
 */

#pragma once

#include "CEvenement.h"

 /**
  * @class CEVAvionVeutDebarquer
  * @brief Classe repr�sentant un �v�nement d'un avion souhaitant d�barquer.
  *
  * Cette classe d�rive de CEvenement et g�re les �v�nements d'avions
  * souhaitant d�barquer � une porte d'embarquement
  */

class CEVAvionVeutDebarquer : public CEvenement {
private:
    CAvion* avion; ///< Pointeur vers l'avion associ� � l'�v�nement.
    static std::vector<CPorteEmbarquement*> gates; ///< Liste statique des portes d'embarquement.

public:
    /**
     * @brief Constructeur par d�faut de la classe CEVAvionVeutDebarquer.
     */
    CEVAvionVeutDebarquer();

    /**
     * @brief Constructeur de la classe CEVAvionVeutDebarquer avec des param�tres.
     * @param p_avion L'avion associ� � l'�v�nement.
     * @param p_temps Temps de l'�v�nement.
     */
    CEVAvionVeutDebarquer(CAvion p_avion, time_t p_temps);

    /**
     * @brief Destructeur de la classe CEVAvionVeutDebarquer.
     */
    ~CEVAvionVeutDebarquer();

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
     * @brief Retourne la liste des portes d'embarquement.
     * @return La liste des portes d'embarquement.
     */
    static std::vector<CPorteEmbarquement*> LireGates() { return gates; }

    /**
     * @brief Ajoute une porte d'embarquement � la liste statique.
     * @param p_gate La porte d'embarquement � ajouter.
     */
    static void AjouterGate(CPorteEmbarquement p_gate){
        CPorteEmbarquement* porteE = new CPorteEmbarquement(p_gate);
        gates.push_back(porteE);
    }


    /**
     * @brief Ex�cute l'�v�nement.
     */
    void run();
};
