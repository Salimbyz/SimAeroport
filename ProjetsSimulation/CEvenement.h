#include <iostream>
#include "CAvion.h"
#include "CPisteAtterissage.h"
#include "CPisteDecollage.h"
#include "CPorteEmbarquement.h"
#include <time.h>
#ifndef CEvenement_H
#define CEvenement_H

/**
 * @class CEvenement
 * @brief Classe de base pour la gestion des �v�nements dans un a�roport.
 *
 * Cette classe repr�sente un �v�nement g�n�ral dans un a�roport. Elle est con�ue pour �tre
 * h�rit�e par des classes sp�cifiques � chaque type d'�v�nement (atterrissage, d�collage, etc.).
 * Elle g�re le temps de d�but de l'�v�nement.
 */
class CEvenement
{
private:
    time_t tempsDebut; ///< Temps de d�but de l'�v�nement.

public:

    /**
     * @brief Constructeur par d�faut.
     */
    CEvenement();

    /**
     * @brief Constructeur de copie.
     *
     * @param p_evenement R�f�rence � l'objet CEvenement � copier.
     */
    CEvenement(CEvenement& p_evenement);

    /**
     * @brief Destructeur.
     */
    ~CEvenement();

    /**
     * @brief �crit le temps de d�but de l'�v�nement.
     *
     * @param p_tempsDebut Temps de d�but � enregistrer.
     */
    void ecrireTempsDebut(time_t p_tempsDebut);

    /**
     * @brief Lit le temps de d�but de l'�v�nement.
     *
     * @return time_t Le temps de d�but de l'�v�nement.
     */
    time_t lireTempsDebut();

    /**
     * @brief Ex�cute l'�v�nement. M�thode � red�finir dans les classes d�riv�es.
     */
    void run();

};
#endif // !CEvenement_H
