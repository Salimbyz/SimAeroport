#pragma once
#include "CEvenement.h"

/**
 * @class CEVAvionQuitteAeroport
 * @brief Classe représentant l'événement où un avion quitte l'aéroport.
 *
 * Cette classe gère les événements liés au départ d'un avion de l'aéroport. Elle
 * conserve les informations sur l'avion et la piste de décollage concernés.
 */
class CEVAvionQuitteAeroport :
    public CEvenement
{
private: 
    CPisteDecollage* pisteDecollage; ///< Pointeur sur la piste de décollage utilisée par l'avion.
    CAvion* avion; ///< Pointeur sur l'avion qui quitte l'aéroport.
public:
    /**
     * @brief Constructeur par défaut.
     */
    CEVAvionQuitteAeroport();

    /**
     * @brief Constructeur avec paramètres.
     *
     * @param p_avion Avion qui quitte l'aéroport.
     * @param p_pisteD Pointeur sur la piste de décollage.
     * @param p_temps Temps de l'événement.
     */
    CEVAvionQuitteAeroport(CAvion p_avion, CPisteDecollage* p_pisteD, time_t p_temps);

    /**
     * @brief Destructeur.
     */
    ~CEVAvionQuitteAeroport();

    /**
     * @brief Retourne la piste de décollage.
     *
     * @return CPisteDecollage& Référence à la piste de décollage.
     */
    CPisteDecollage& LirePisteDecollage() {
        return *pisteDecollage;
    }

    /**
     * @brief Modifie la piste de décollage.
     *
     * @param p_pisteDecollage Référence à la nouvelle piste de décollage.
     */
    void ModifierPisteDecollage(CPisteDecollage& p_pisteDecollage) {
        pisteDecollage = &p_pisteDecollage;
    }

    /**
     * @brief Retourne l'avion concerné par l'événement.
     *
     * @return CAvion L'avion qui quitte l'aéroport.
     */
    CAvion LireAvion() { return *avion; }

    /**
     * @brief Modifie l'avion concerné par l'événement.
     *
     * @param p_avion Avion qui quitte l'aéroport.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }
    

    /**
     * @brief Exécute l'événement de départ de l'avion.
     */
    void run();
};

