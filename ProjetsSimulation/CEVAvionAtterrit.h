#pragma once
#include "CEvenement.h"
#define TempsAtterisssage = 90
#ifndef CEVDebutAtterrissage 
#define CEVDebutAtterrissage

/**
 * @class CEVAvionAtterrit
 * @brief Classe repr�sentant un �v�nement d'atterrissage d'un avion.
 *
 * Cette classe d�rive de CEvenement et g�re les �v�nements d'atterrissage
 * d'avions sur une piste d'atterrissage sp�cifique.
 */
class CEVAvionAtterrit: public CEvenement
{
private:
	CPisteAtterissage* pisteAtterissage; ///< Pointeur sur la piste d'atterrissage utilis�e pour l'atterrissage.
	CAvion* avion; ///< Pointeur sur l'avion qui atterrit.
public:
    /**
     * @brief Constructeur par d�faut.
     */
    CEVAvionAtterrit();

    /**
     * @brief Destructeur.
     */
    ~CEVAvionAtterrit();

    /**
     * @brief Constructeur avec param�tres.
     * @param p_avion Avion devant atterrir.
     * @param p_pisteAtt Pointeur sur la piste d'atterrissage.
     * @param p_temps Temps de l'�v�nement d'atterrissage.
     */
    CEVAvionAtterrit(CAvion p_avion, CPisteAtterissage* p_pisteAtt, time_t p_temps);

    /**
     * @brief Retourne la piste d'atterrissage.
     * @return CPisteAtterissage La piste d'atterrissage utilis�e.
     */
	CPisteAtterissage LirePisteAtterissage() { return *pisteAtterissage; }
	
    /**
     * @brief Modifie la piste d'atterrissage.
     * @param p_pisteAtterissage Nouvelle piste d'atterrissage.
     */
    void ModifierPisteAtterissage(CPisteAtterissage p_pisteAtterissage) { *pisteAtterissage = p_pisteAtterissage; }

    /**
     * @brief Retourne l'avion concern� par l'�v�nement.
     * @return CAvion L'avion qui atterrit.
     */
	CAvion LireAvion() { return *avion; }
	
    /**
     * @brief Modifie l'avion concern� par l'�v�nement.
     * @param p_avion Nouvel avion � atterrir.
     */
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    /**
     * @brief Ex�cute l'�v�nement d'atterrissage.
     */
	void run();

};
#endif // !CEVDebutAtterrissage 


