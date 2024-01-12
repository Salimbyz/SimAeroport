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
 * @brief Classe de base pour la gestion des événements dans un aéroport.
 *
 * Cette classe représente un événement général dans un aéroport. Elle est conçue pour être
 * héritée par des classes spécifiques à chaque type d'événement (atterrissage, décollage, etc.).
 * Elle gère le temps de début de l'événement.
 */
class CEvenement
{
private:
    time_t tempsDebut; ///< Temps de début de l'événement.

public:

    /**
     * @brief Constructeur par défaut.
     */
    CEvenement();

    /**
     * @brief Constructeur de copie.
     *
     * @param p_evenement Référence à l'objet CEvenement à copier.
     */
    CEvenement(CEvenement& p_evenement);

    /**
     * @brief Destructeur.
     */
    ~CEvenement();

    /**
     * @brief Écrit le temps de début de l'événement.
     *
     * @param p_tempsDebut Temps de début à enregistrer.
     */
    void ecrireTempsDebut(time_t p_tempsDebut);

    /**
     * @brief Lit le temps de début de l'événement.
     *
     * @return time_t Le temps de début de l'événement.
     */
    time_t lireTempsDebut();

    /**
     * @brief Exécute l'événement. Méthode à redéfinir dans les classes dérivées.
     */
    void run();

};
#endif // !CEvenement_H
