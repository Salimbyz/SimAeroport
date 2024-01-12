#pragma once
#include "CEvenement.h"
#define TempsAtterisssage = 90
#ifndef CEVDebutAtterrissage 
#define CEVDebutAtterrissage

/**
 * @class CEVAvionAtterrit
 * @brief Classe représentant un événement d'atterrissage d'un avion.
 *
 * Cette classe dérive de CEvenement et gère les événements d'atterrissage
 * d'avions sur une piste d'atterrissage spécifique.
 */
class CEVAvionAtterrit: public CEvenement
{
private:
	CPisteAtterissage* pisteAtterissage; ///< Pointeur sur la piste d'atterrissage utilisée pour l'atterrissage.
	CAvion* avion; ///< Pointeur sur l'avion qui atterrit.
public:
    /**
     * @brief Constructeur par défaut.
     */
    CEVAvionAtterrit();

    /**
     * @brief Destructeur.
     */
    ~CEVAvionAtterrit();

    /**
     * @brief Constructeur avec paramètres.
     * @param p_avion Avion devant atterrir.
     * @param p_pisteAtt Pointeur sur la piste d'atterrissage.
     * @param p_temps Temps de l'événement d'atterrissage.
     */
    CEVAvionAtterrit(CAvion p_avion, CPisteAtterissage* p_pisteAtt, time_t p_temps);

    /**
     * @brief Retourne la piste d'atterrissage.
     * @return CPisteAtterissage La piste d'atterrissage utilisée.
     */
	CPisteAtterissage LirePisteAtterissage() { return *pisteAtterissage; }
	
    /**
     * @brief Modifie la piste d'atterrissage.
     * @param p_pisteAtterissage Nouvelle piste d'atterrissage.
     */
    void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) { *pisteAtterissage = p_pisteAtterissage; }

    /**
     * @brief Retourne l'avion concerné par l'événement.
     * @return CAvion L'avion qui atterrit.
     */
	CAvion LireAvion() { return *avion; }
	
    /**
     * @brief Modifie l'avion concerné par l'événement.
     * @param p_avion Nouvel avion à atterrir.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief Exécute l'événement d'atterrissage.
     */
	void run();

};
#endif // !CEVDebutAtterrissage 


