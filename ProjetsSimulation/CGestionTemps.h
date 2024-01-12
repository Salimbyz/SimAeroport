#pragma once
#include <vector>
#include "CEntree.h"
using namespace std;
class CGestionTemps
{
private:
	static double tempsRetardDepart;
	static int nbretards;
	static int nbavances;
public:
	static void AjouterTempsDepart(double tempsretard) {
		if (tempsretard < 0) {
			nbretards++;
		}
		else {
			nbretards++;
		}
		tempsRetardDepart+=tempsretard;

	}
	static void AfficherTempsRetardTotal() {
		int heures = (int)(tempsRetardDepart / 3600);
		int minutes = (int)((((int)tempsRetardDepart % 3600) / 60));
		int secondes = (int)tempsRetardDepart % 60;
		int tempsmoy =(int) tempsRetardDepart / 20;
		int heuresmoy = (int)tempsmoy / 3600;
		int minutesmoy = (int)((((int)tempsmoy % 3600) / 60));
		int secondesmoy = (int)tempsmoy % 60;
		std::cout << tempsRetardDepart << " secondes de retard soit : " << heures <<":" << minutes<<":"<<secondes<<" Soit en moyenne : "<< minutesmoy << "m" << secondesmoy << std::endl;
		std::cout << nbretards << " Avions sortent en retard et " << nbavances <<" sortent en avance ou à l'heure";
	}
};

