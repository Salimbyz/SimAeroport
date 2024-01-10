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

    time_t stringToTimeT(const std::string& timeStr) {
        tm tm = {};
        istringstream ss(timeStr);
        ss >> std::get_time(&tm, "%H:%M");
        // Ajustement de la date à un point fixe (par exemple, le 1er janvier 1970)
        tm.tm_year = 124; // Année depuis 1900
        tm.tm_mon = 0;   // Janvier
        tm.tm_mday = 15;  //Jour
        return std::mktime(&tm);
    }

    void printTimeT(time_t time) {
        tm tm;
        localtime_s(&tm, &time);
        cout << std::put_time(&tm, "%H:%M") << std::endl;
    }

    /**
     * @brief Lit les données des avions à partir d'un fichier et les stocke dans un vecteur.
     * @param nomFichier Le nom du fichier à lire.
     * @return Un vecteur contenant des objets CAvion.
     * @throw std::invalid_argument si le fichier ne peut pas être ouvert.
     */
    vector<CAvion> lireAvions(const string& nomFichier) {
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
            throw new invalid_argument("");
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
            throw new invalid_argument("erreur");
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
            throw new invalid_argument("erreur");
        }
    }
};