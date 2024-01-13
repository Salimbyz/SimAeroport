/**
 * @file CEVAvionVeutDecoller.h
 * @brief Définition de la classe CEVAvionVeutDecoller.
 */

#pragma once

#include "CEvenement.h"

 /**
 * @class CEVAvionVeutDecoller
 * @brief Classe représentant un événement d'un avion souhaitant décoller.
 *
 * Cette classe dérive de CEvenement et gère les événements d'avions
 * souhaitant décoller
 */

class CEVAvionVeutDecoller : public CEvenement {
private:
    static std::vector<CPisteDecollage*> pistesDecollage; ///< Liste statique des pistes de décollage.
    CAvion* avion; ///< Pointeur vers l'avion associé à l'événement.

public:
    /**
     * @brief Constructeur par défaut de la classe CEVAvionVeutDecoller.
     */
    CEVAvionVeutDecoller();

    /**
     * @brief Destructeur de la classe CEVAvionVeutDecoller.
     */
    ~CEVAvionVeutDecoller();

    /**
     * @brief Constructeur de la classe CEVAvionVeutDecoller avec des paramètres.
     * @param p_avion L'avion associé à l'événement.
     * @param p_temps Temps de l'événement.
     */
    CEVAvionVeutDecoller(CAvion p_avion, time_t p_temps);

    /**
     * @brief Mutateur pour modifier l'avion associé à l'événement.
     * @param p_avion Le nouvel avion.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief Accesseur pour lire l'avion associé à l'événement.
     * @return L'avion associé à l'événement.
     */
    CAvion LireAvion() { return *avion; }

    /**
     * @brief Retourne la liste des pistes de décollage.
     * @return La liste des pistes de décollage.
     */
    static std::vector<CPisteDecollage*> LirePisteDecollage() { return pistesDecollage; }

    /**
     * @brief Ajoute une piste de décollage à la liste statique.
     * @param p_pisteD La piste de décollage à ajouter.
     */
    static void AjouterPiste(CPisteDecollage p_pisteD) {
        CPisteDecollage* pisteD = new CPisteDecollage(p_pisteD);
        pistesDecollage.push_back(pisteD);
    }

    /**
     * @brief Exécute l'événement.
     */
    void run();
};
