/**
 * @file CEVAvionVeutDecoller.h
 * @brief D�finition de la classe CEVAvionVeutDecoller.
 */

#pragma once

#include "CEvenement.h"

 /**
 * @class CEVAvionVeutDecoller
 * @brief Classe repr�sentant un �v�nement d'un avion souhaitant d�coller.
 *
 * Cette classe d�rive de CEvenement et g�re les �v�nements d'avions
 * souhaitant d�coller
 */

class CEVAvionVeutDecoller : public CEvenement {
private:
    static std::vector<CPisteDecollage*> pistesDecollage; ///< Liste statique des pistes de d�collage.
    CAvion* avion; ///< Pointeur vers l'avion associ� � l'�v�nement.

public:
    /**
     * @brief Constructeur par d�faut de la classe CEVAvionVeutDecoller.
     */
    CEVAvionVeutDecoller();

    /**
     * @brief Destructeur de la classe CEVAvionVeutDecoller.
     */
    ~CEVAvionVeutDecoller();

    /**
     * @brief Constructeur de la classe CEVAvionVeutDecoller avec des param�tres.
     * @param p_avion L'avion associ� � l'�v�nement.
     * @param p_temps Temps de l'�v�nement.
     */
    CEVAvionVeutDecoller(CAvion p_avion, time_t p_temps);

    /**
     * @brief Mutateur pour modifier l'avion associ� � l'�v�nement.
     * @param p_avion Le nouvel avion.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief Accesseur pour lire l'avion associ� � l'�v�nement.
     * @return L'avion associ� � l'�v�nement.
     */
    CAvion LireAvion() { return *avion; }

    /**
     * @brief Retourne la liste des pistes de d�collage.
     * @return La liste des pistes de d�collage.
     */
    static std::vector<CPisteDecollage*> LirePisteDecollage() { return pistesDecollage; }

    /**
     * @brief Ajoute une piste de d�collage � la liste statique.
     * @param p_pisteD La piste de d�collage � ajouter.
     */
    static void AjouterPiste(CPisteDecollage p_pisteD) {
        CPisteDecollage* pisteD = new CPisteDecollage(p_pisteD);
        pistesDecollage.push_back(pisteD);
    }

    /**
     * @brief Ex�cute l'�v�nement.
     */
    void run();
};
