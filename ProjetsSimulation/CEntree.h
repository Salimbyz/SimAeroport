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
 * @brief Classe pour la lecture et le traitement des donn�es d'entr�e.
 *
 * Cette classe est responsable de la lecture des donn�es � partir de fichiers
 * et de la cr�ation de vecteurs d'objets correspondants.
 */
class CEntree
{
private:

public :


    vector<int> genererRetardsPoisson(int moyenne, int nombre, double probaSansRetard) {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::poisson_distribution<> d(moyenne);
        std::uniform_real_distribution<> proba(0.0, 1.0);

        std::vector<int> retards;
        for (int n = 0; n < nombre; ++n) {
            if (proba(gen) > probaSansRetard) {
                // G�n�rer un retard
                retards.push_back(d(gen));
            }
            else {
                // Pas de retard ou retard minime
                retards.push_back(0);
            }
        }

        return retards;
    }

    time_t stringToTimeT(const std::string& timeStr) {
        tm tm = {};
        istringstream ss(timeStr);
        cout << timeStr;
        ss >> std::get_time(&tm, "%H:%M");
        // Ajustement de la date � un point fixe (par exemple, le 1er janvier 1970)
        tm.tm_year = 124; // Ann�e depuis 1900
        tm.tm_mon = 0;   // Janvier
        tm.tm_mday = 15;  //Jour
        return std::mktime(&tm);
    }

    static void printTimeT(time_t time) {
        tm tm;
        localtime_s(&tm, &time);
        cout << std::put_time(&tm, "%H:%M") << std::endl;
    }

    /**
     * @brief Lit les donn�es des avions � partir d'un fichier et les stocke dans un vecteur.
     * @param nomFichier Le nom du fichier � lire.
     * @return Un vecteur contenant des objets CAvion.
     * @throw std::invalid_argument si le fichier ne peut pas �tre ouvert.
     */
    vector<CAvion> lireAvions(const string& nomFichier) {
        CEntree entree;
        ifstream fichier;
        fichier.open(nomFichier, ifstream::in);
        string ligne;
        vector<CAvion> vecteurAvions;
        if (!fichier.fail())
        {
            // Sauter la ligne d'en-t�te
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
            throw new invalid_argument("Le fichier n'a pas pu �tre ouvert");
        }
    }

    /**
     * @brief Lit les donn�es des pistes d'atterrissage � partir d'un fichier et les stocke dans un vecteur.
     * @param nomFichier Le nom du fichier � lire.
     * @return Un vecteur contenant des objets CPisteAtterissage.
     * @throw std::invalid_argument si le fichier ne peut pas �tre ouvert.
     */
    vector<CPisteAtterissage> lirePisteAtterissage(const string& nomFichier)
    {
        ifstream fichier;
        fichier.open(nomFichier, ifstream::in);
        string ligne;
        vector<CPisteAtterissage> vecteurAtterissage;
        if (!fichier.fail()) {

            // Sauter la ligne d'en-t�te
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
            throw new invalid_argument("Le fichier n'a pas pu �tre ouvert");
        }
    }

    /**
    * @brief Lit les donn�es des pistes de d�collage � partir d'un fichier et les stocke dans un vecteur.
    * @param nomFichier Le nom du fichier � lire.
    * @return Un vecteur contenant des objets CPisteDecollage.
    * @throw std::invalid_argument si le fichier ne peut pas �tre ouvert.
    */
    vector<CPisteDecollage> lirePisteDecollage(const string& nomFichier)
    {
        ifstream fichier;
        fichier.open(nomFichier, ifstream::in);
        string ligne;
        vector<CPisteDecollage> vecteurDecollage;
        if (!fichier.fail()) {

            // Sauter la ligne d'en-t�te
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
            throw new invalid_argument("Le fichier n'a pas pu �tre ouvert");
        }
    }
    vector<CPorteEmbarquement> lirePorteEmbarquement(const string& nomFichier)
    {
        ifstream fichier;
        fichier.open(nomFichier, ifstream::in);
        string ligne;
        vector<CPorteEmbarquement> vecteurEmbarquement;
        if (!fichier.fail()) {

            // Sauter la ligne d'en-t�te
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