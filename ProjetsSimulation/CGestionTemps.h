#pragma once
#include <vector>
#include "CEntree.h"
using namespace std;
/**
 * @class CGestionTemps
 * @brief Classe pour la gestion des temps de retard et d'avance des d�parts d'avions.
 *
 * Cette classe fournit des m�thodes statiques pour g�rer et afficher les statistiques
 * li�es aux retards et aux avances des d�parts d'avions dans un a�roport. Elle permet
 * d'ajouter des temps de retard et d'afficher le temps de retard total ainsi que la moyenne.
 */
class CGestionTemps
{
private:
	static double tempsRetardDepart; ///< Temps total de retard cumul�.
	static int nbretards; ///< Nombre total d'avions ayant subi un retard.
	static int nbavances; ///< Nombre total d'avions partis en avance ou � l'heure.

public:
	/**
	 * @brief Ajoute un temps de retard ou d'avance au total.
	 *
	 * @param tempsretard Temps de retard (positif) ou d'avance (n�gatif) en secondes.
	 */
	static void AjouterTempsDepart(double tempsretard) {
		if (tempsretard < 60) {
			nbavances++;
		}
		else {
			nbretards++;
		}
		tempsRetardDepart+=tempsretard;
	}

	/**
	 * @brief Affiche le temps total de retard et la moyenne par avion.
	 *
	 * Cette m�thode calcule et affiche le temps total de retard en heures, minutes et secondes,
	 * ainsi que le temps moyen de retard par avion, et le nombre d'avions en retard ou en avance.
	 */
	static void AfficherTempsRetardTotal() {
		int heures = (int)(tempsRetardDepart / 3600);
		int minutes = (int)((((int)tempsRetardDepart % 3600) / 60));
		int secondes = (int)tempsRetardDepart % 60;
		int tempsmoy =(int) tempsRetardDepart / 20;
		int heuresmoy = (int)tempsmoy / 3600;
		int minutesmoy = (int)((((int)tempsmoy % 3600) / 60));
		int secondesmoy = (int)tempsmoy % 60;
		std::cout << tempsRetardDepart << " secondes de retard soit : " << heures <<":" << minutes<<":"<<secondes<<" Soit en moyenne : "<< minutesmoy << "m" << secondesmoy << std::endl;
		std::cout << nbretards << " Avions sortent en retard et " << nbavances <<" sortent en avance ou a l'heure";
	}
};

