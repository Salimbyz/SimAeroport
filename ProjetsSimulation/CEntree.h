#pragma once
#include <iostream>
#include <time.h>
#include <locale>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "CAvion.h"
#include "CPisteDecollage.h"
#include "CPisteAtterissage.h"
#include "CPorteEmbarquement.h"
#include <random>
using namespace std;

/**
 * @class CEntree
 * @brief Classe pour la lecture et le traitement des données d'entrée.
 *
 * Cette classe est responsable de la lecture des données à partir de fichiers
 * et de la création de vecteurs d'objets correspondants.
 */
class CEntree
{
private:

public :


    /**
 * @brief Génère un vecteur de retards basé sur une distribution de Poisson.
 *
 * Cette fonction crée un vecteur de retards pour un nombre donné d'événements.
 * Chaque retard est déterminé en utilisant une distribution de Poisson. Il existe également
 * une probabilité qu'il n'y ait aucun retard.
 *
 * @param moyenne La moyenne de la distribution de Poisson.
 * @param nombre Le nombre total d'événements pour lesquels générer des retards.
 * @param probaSansRetard La probabilité qu'un événement n'ait pas de retard.
 * @return std::vector<int> Un vecteur contenant les retards générés pour chaque événement.
 */
    static vector<int> genererRetardsPoisson(int moyenne, int nombre, double probaSansRetard) {
        random_device  aleatoire;
        mt19937 gen(aleatoire());

        poisson_distribution<> d(moyenne);
        uniform_real_distribution<> proba(0.0, 1.0);

        std::vector<int> retards;
        for (int n = 0; n < nombre; ++n) {
            if (proba(gen) > probaSansRetard) {
                // Générer un retard
                retards.push_back(d(gen));
            }
            else {
                // Pas de retard ou retard minime
                retards.push_back(0);
            }
        }

        return retards;
    }

    /**
     * @brief Convertit une chaîne de caractères représentant une heure au format time_t.
     *
     * Cette fonction prend une chaîne de caractères représentant une heure au format HH:MM
     * et la convertit en une valeur time_t. La date est fixée à un point arbitraire (par exemple, le 15 janvier 1970).
     *
     * @param tempsConvertir La chaîne de caractères à convertir au format HH:MM.
     * @return time_t La représentation time_t de l'heure donnée.
     */
    time_t stringToTimeT(const std::string& tempsConvertir) {
        tm tm = {};
        istringstream ss(tempsConvertir);

        ss >> std::get_time(&tm, "%H:%M");
        // Ajustement de la date à un point fixe (par exemple, le 1er janvier 1970)
        tm.tm_year = 124; // Année depuis 1900
        tm.tm_mon = 0;   // Janvier
        tm.tm_mday = 15;  //Jour
        return std::mktime(&tm);
    }

    /**
     * @brief Affiche une valeur time_t en tant qu'heure au format HH:MM.
     *
     * Cette fonction prend une valeur time_t et l'affiche sous forme d'heure
     * au format HH:MM. Cela peut être utilisé pour afficher des heures stockées dans des
     * structures time_t.
     *
     * @param time La valeur time_t à afficher.
     */
    static void printTimeT(time_t time) {
        tm tm;
        localtime_s(&tm, &time);
        cout << put_time(&tm, "%H:%M") << endl;
    }

    /**
     * @brief Lit les données des avions à partir d'un fichier et les stocke dans un vecteur.
     * @param nomFichier Le nom du fichier à lire.
     * @return Un vecteur contenant des objets CAvion.
     * @throw std::invalid_argument si le fichier ne peut pas être ouvert.
     */
    vector<CAvion> lireAvions(const string& nomFichier) {
        CEntree entree;
        ifstream fichier;
        fichier.open(nomFichier, ifstream::in);
        string ligne;
        vector<CAvion> vecteurAvions;
        if (!fichier.fail())
        {
            // Sauter la ligne d'en-tête
            getline(fichier, ligne);

            while (getline(fichier, ligne)) {
                istringstream ss(ligne);
                string token;

                unsigned int id;
                string arrivee, depart, etat;
                time_t tempsArrivee, tempsDepart;
                tempsArrivee = 0;
                tempsDepart = 0;
                //Identifiant
                getline(ss, token, ',');
                id = static_cast<unsigned int>(stoul(token));

                getline(ss, arrivee, ',');
                getline(ss, depart, ',');

                
                tempsArrivee = stringToTimeT(arrivee);
                tempsDepart = stringToTimeT(depart);

                

                //Etat de l'avion
                getline(ss, etat, ',');

                Etat etat2 = CAvion::stringToEnum(etat);

                CAvion avion;
                avion.modifierIdAvion(id);
                avion.modifierHeureArriveePrevue(tempsArrivee);
                avion.modifierHeureDepartPrevue(tempsDepart);
                avion.modifierEtat(etat2);
                vecteurAvions.push_back(avion);
            }

            return vecteurAvions;
        }
        else {
            throw new invalid_argument("Le fichier n'a pas pu être ouvert");
        }
    }

    /**
     * @brief Lit les données des pistes d'atterrissage à partir d'un fichier et les stocke dans un vecteur.
     * @param nomFichier Le nom du fichier à lire.
     * @return Un vecteur contenant des objets CPisteAtterissage.
     * @throw std::invalid_argument si le fichier ne peut pas être ouvert.
     */
    vector<CPisteAtterissage> lirePisteAtterissage(const string& nomFichier)
    {
        ifstream fichier;
        fichier.open(nomFichier, ifstream::in);
        string ligne;
        vector<CPisteAtterissage> vecteurAtterissage;
        if (!fichier.fail()) {

            // Sauter la ligne d'en-tête
            getline(fichier, ligne);

            while (getline(fichier, ligne)) {
                istringstream ss(ligne);
                string token;

                unsigned int id;

                //Identifiant
                getline(ss, token, ',');
                id = static_cast<unsigned int>(stoul(token));


                CPisteAtterissage pisteAtterissage;
                pisteAtterissage.ecrireIdPisteA(id);
                vecteurAtterissage.push_back(pisteAtterissage);
            }
            return vecteurAtterissage;
        }
        else {
            throw new invalid_argument("Le fichier n'a pas pu être ouvert");
        }
    }

    /**
    * @brief Lit les données des pistes de décollage à partir d'un fichier et les stocke dans un vecteur.
    * @param nomFichier Le nom du fichier à lire.
    * @return Un vecteur contenant des objets CPisteDecollage.
    * @throw std::invalid_argument si le fichier ne peut pas être ouvert.
    */
    vector<CPisteDecollage> lirePisteDecollage(const string& nomFichier)
    {
        ifstream fichier;
        fichier.open(nomFichier, ifstream::in);
        string ligne;
        vector<CPisteDecollage> vecteurDecollage;
        if (!fichier.fail()) {

            // Sauter la ligne d'en-tête
            getline(fichier, ligne);

            while (getline(fichier, ligne)) {
                istringstream ss(ligne);
                string token;

                unsigned int id;

                //Identifiant
                getline(ss, token, ',');
                id = static_cast<unsigned int>(stoul(token));


                CPisteDecollage pisteDecollage;
                pisteDecollage.ecrireIdPisteD(id);
                vecteurDecollage.push_back(pisteDecollage);
            }
            return vecteurDecollage;
        }
        else {
            throw new invalid_argument("Le fichier n'a pas pu être ouvert");
        }
    }
    vector<CPorteEmbarquement> lirePorteEmbarquement(const string& nomFichier)
    {
        ifstream fichier;
        fichier.open(nomFichier, ifstream::in);
        string ligne;
        vector<CPorteEmbarquement> vecteurEmbarquement;
        if (!fichier.fail()) {

            // Sauter la ligne d'en-tête
            getline(fichier, ligne);

            while (getline(fichier, ligne)) {
                istringstream ss(ligne);
                string token;

                unsigned int id;

                //Identifiant
                getline(ss, token, ',');
                id = static_cast<unsigned int>(stoul(token));


                CPorteEmbarquement porteEmbarquement;
                porteEmbarquement.ecrireIdPorteE(id);
                vecteurEmbarquement.push_back(porteEmbarquement);
            }
            return vecteurEmbarquement;
        }
        else {
            throw new invalid_argument("erreur");
        }
    }
};