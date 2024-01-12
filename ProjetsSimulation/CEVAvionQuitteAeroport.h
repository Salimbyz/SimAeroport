#pragma once
#include "CEvenement.h"

/**
 * @class CEVAvionQuitteAeroport
 * @brief Classe repr�sentant l'�v�nement o� un avion quitte l'a�roport.
 *
 * Cette classe g�re les �v�nements li�s au d�part d'un avion de l'a�roport. Elle
 * conserve les informations sur l'avion et la piste de d�collage concern�s.
 */
class CEVAvionQuitteAeroport :
    public CEvenement
{
private: 
    CPisteDecollage* pisteDecollage; ///< Pointeur sur la piste de d�collage utilis�e par l'avion.
    CAvion* avion; ///< Pointeur sur l'avion qui quitte l'a�roport.
public:
    /**
     * @brief Constructeur par d�faut.
     */
    CEVAvionQuitteAeroport();

    /**
     * @brief Constructeur avec param�tres.
     *
     * @param p_avion Avion qui quitte l'a�roport.
     * @param p_pisteD Pointeur sur la piste de d�collage.
     * @param p_temps Temps de l'�v�nement.
     */
    CEVAvionQuitteAeroport(CAvion p_avion, CPisteDecollage* p_pisteD, time_t p_temps);

    /**
     * @brief Destructeur.
     */
    ~CEVAvionQuitteAeroport();

    /**
     * @brief Retourne la piste de d�collage.
     *
     * @return CPisteDecollage& R�f�rence � la piste de d�collage.
     */
    CPisteDecollage& LirePisteDecollage() {
        return *pisteDecollage;
    }

    /**
     * @brief Modifie la piste de d�collage.
     *
     * @param p_pisteDecollage R�f�rence � la nouvelle piste de d�collage.
     */
    void ModifierPisteDecollage(CPisteDecollage& p_pisteDecollage) {
        pisteDecollage = &p_pisteDecollage;
    }

    /**
     * @brief Retourne l'avion concern� par l'�v�nement.
     *
     * @return CAvion L'avion qui quitte l'a�roport.
     */
    CAvion LireAvion() { return *avion; }

    /**
     * @brief Modifie l'avion concern� par l'�v�nement.
     *
     * @param p_avion Avion qui quitte l'a�roport.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }
    

    /**
     * @brief Ex�cute l'�v�nement de d�part de l'avion.
     */
    void run();
};

