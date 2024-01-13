/**
 * @file CEVAvionVeutAtterrir.h
 * @brief D�finition de la classe CEVAvionVeutAtterrir.
 */

#pragma once

#include "CEvenement.h"
#include <vector>

 /**
  * @class CEVAvionVeutAtterrir
  * @brief Classe repr�sentant un �v�nement d'un avion souhaitant atterrir.
  *
  * Cette classe d�rive de CEvenement et g�re les �v�nements d'avions
  * souhaitant atterrir
  */

class CEVAvionVeutAtterrir : public CEvenement {
private:
    static std::vector<CPisteAtterissage*> pisteAtterissage; ///< Liste statique des pistes d'atterrissage disponibles.
    CAvion* avion; ///< Pointeur vers l'avion associ� � l'�v�nement.

public:
    /**
     * @brief Constructeur par d�faut de la classe CEVAvionVeutAtterrir.
     */
    CEVAvionVeutAtterrir();

    /**
     * @brief Destructeur de la classe CEVAvionVeutAtterrir.
     */
    ~CEVAvionVeutAtterrir();

    /**
     * @brief Constructeur de la classe CEVAvionVeutAtterrir avec des param�tres.
     * @param p_avion L'avion associ� � l'�v�nement.
     * @param p_temp Temps de l'�v�nement.
     */
    CEVAvionVeutAtterrir(CAvion p_avion, time_t p_temp);

    /**
     * @brief Ajoute une piste d'atterrissage � la liste statique.
     * @param p_pisteA La piste d'atterrissage � ajouter.
     */
    static void AjouterPiste(CPisteAtterissage p_pisteA) {
        CPisteAtterissage* p_piste = new CPisteAtterissage(p_pisteA);
        pisteAtterissage.push_back(p_piste);
    }

    /**
     * @brief Retourne la liste des pistes d'atterrissage disponibles.
     * @return La liste des pistes d'atterrissage.
     */
    static std::vector<CPisteAtterissage*> LirePisteAtterissage(){ return pisteAtterissage; }

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
     * @brief Ex�cute l'�v�nement.
     */
    void run();
};
