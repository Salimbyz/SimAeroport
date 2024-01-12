#pragma once
#include "CEvenement.h"

/**
 * @class CEVAvionDecolle
 * @brief Classe représentant un événement de décollage d'un avion.
 *
 * Cette classe dérive de CEvenement et gère les événements de décollage
 * d'avions sur une piste de décollage spécifique.
 */
class CEVAvionDecolle :
    public CEvenement
{
private :
    CPisteDecollage* pisteDecollage; ///< Pointeur sur la piste de décollage utilisée pour le décollage.
    CAvion* avion; ///< Pointeur sur l'avion qui décolle.
public :
    /**
     * @brief Constructeur par défaut.
     */
    CEVAvionDecolle();

    /**
     * @brief Destructeur.
     */
    ~CEVAvionDecolle();

    /**
     * @brief Constructeur avec paramètres.
     * @param p_avion Avion devant décoller.
     * @param p_pisteDecollage Pointeur sur la piste de décollage.
     * @param p_temps Temps de l'événement de décollage.
     */
    CEVAvionDecolle(CAvion p_avion, CPisteDecollage* p_pisteDecollage, time_t p_temps);

    /**
     * @brief Modifie l'avion concerné par l'événement.
     * @param p_avion Nouvel avion à décoller.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief Modifie la piste de décollage.
     * @param p_pisteDecollage Nouvelle piste de décollage.
     */
    void ModifierPisteDecollage(CPisteDecollage& p_pisteDecollage) {
        pisteDecollage = &p_pisteDecollage;
    }

    /**
     * @brief Retourne l'avion concerné par l'événement.
     * @return CAvion L'avion qui décolle.
     */
    CAvion LireAvion() { return *avion; }

    /**
     * @brief Retourne la piste de décollage.
     * @return CPisteDecollage& Référence à la piste de décollage utilisée.
     */
    CPisteDecollage& LirePisteDecollage() {
        return *pisteDecollage;
    }

    /**
     * @brief Exécute l'événement de décollage.
     */
    void run();

};

