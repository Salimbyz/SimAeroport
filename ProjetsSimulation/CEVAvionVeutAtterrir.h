/**
 * @file CEVAvionVeutAtterrir.h
 * @brief Définition de la classe CEVAvionVeutAtterrir.
 */

#pragma once

#include "CEvenement.h"
#include <vector>

 /**
  * @class CEVAvionVeutAtterrir
  * @brief Classe représentant un événement d'un avion souhaitant atterrir.
  *
  * Cette classe dérive de CEvenement et gère les événements d'avions
  * souhaitant atterrir
  */

class CEVAvionVeutAtterrir : public CEvenement {
private:
    static std::vector<CPisteAtterissage*> pisteAtterissage; ///< Liste statique des pistes d'atterrissage disponibles.
    CAvion* avion; ///< Pointeur vers l'avion associé à l'événement.

public:
    /**
     * @brief Constructeur par défaut de la classe CEVAvionVeutAtterrir.
     */
    CEVAvionVeutAtterrir();

    /**
     * @brief Destructeur de la classe CEVAvionVeutAtterrir.
     */
    ~CEVAvionVeutAtterrir();

    /**
     * @brief Constructeur de la classe CEVAvionVeutAtterrir avec des paramètres.
     * @param p_avion L'avion associé à l'événement.
     * @param p_temp Temps de l'événement.
     */
    CEVAvionVeutAtterrir(CAvion p_avion, time_t p_temp);

    /**
     * @brief Ajoute une piste d'atterrissage à la liste statique.
     * @param p_pisteA La piste d'atterrissage à ajouter.
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
     * @brief Exécute l'événement.
     */
    void run();
};
