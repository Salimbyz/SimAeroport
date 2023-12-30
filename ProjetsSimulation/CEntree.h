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

class CEntree
{
private:

public:
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

                tm tmTempsArrivee = {};
                tm tmTempsDepart = {};
                istringstream ss1(arrivee);
                ss1 >> get_time(&tmTempsArrivee, "%Hh%M");
                if (!ss1.fail()) {
                    tempsArrivee = mktime(&tmTempsArrivee);
                }
                istringstream ss2(depart);
                ss2 >> get_time(&tmTempsDepart, "%Hh%M");
                if (!ss2.fail()) {
                    tempsDepart = mktime(&tmTempsDepart);
                }

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