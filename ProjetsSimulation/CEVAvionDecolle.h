#pragma once
#include "CEvenement.h"

/**
 * @class CEVAvionDecolle
 * @brief Classe repr�sentant un �v�nement de d�collage d'un avion.
 *
 * Cette classe d�rive de CEvenement et g�re les �v�nements de d�collage
 * d'avions sur une piste de d�collage sp�cifique.
 */
class CEVAvionDecolle :
    public CEvenement
{
private :
    CPisteDecollage* pisteDecollage; ///< Pointeur sur la piste de d�collage utilis�e pour le d�collage.
    CAvion* avion; ///< Pointeur sur l'avion qui d�colle.
public :
    /**
     * @brief Constructeur par d�faut.
     */
    CEVAvionDecolle();

    /**
     * @brief Destructeur.
     */
    ~CEVAvionDecolle();

    /**
     * @brief Constructeur avec param�tres.
     * @param p_avion Avion devant d�coller.
     * @param p_pisteDecollage Pointeur sur la piste de d�collage.
     * @param p_temps Temps de l'�v�nement de d�collage.
     */
    CEVAvionDecolle(CAvion p_avion, CPisteDecollage* p_pisteDecollage, time_t p_temps);

    /**
     * @brief Modifie l'avion concern� par l'�v�nement.
     * @param p_avion Nouvel avion � d�coller.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief Modifie la piste de d�collage.
     * @param p_pisteDecollage Nouvelle piste de d�collage.
     */
    void ModifierPisteDecollage(CPisteDecollage& p_pisteDecollage) {
        pisteDecollage = &p_pisteDecollage;
    }

    /**
     * @brief Retourne l'avion concern� par l'�v�nement.
     * @return CAvion L'avion qui d�colle.
     */
    CAvion LireAvion() { return *avion; }

    /**
     * @brief Retourne la piste de d�collage.
     * @return CPisteDecollage& R�f�rence � la piste de d�collage utilis�e.
     */
    CPisteDecollage& LirePisteDecollage() {
        return *pisteDecollage;
    }

    /**
     * @brief Ex�cute l'�v�nement de d�collage.
     */
    void run();

};

