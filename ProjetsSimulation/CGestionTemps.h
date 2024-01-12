#pragma once
#include <vector>
#include "CEntree.h"
using namespace std;
class CGestionTemps
{
private:
	static vector<int> tempsRetardArrivee;
	static vector<int> tempsRetardDepart;
public:
	static void AjouterTempsDepart(time_t p_temps) {
		tempsRetardDepart.push_back(p_temps);
	}
	static void AfficherTempsDepart() {
		for (unsigned int i = 0; i < tempsRetardDepart.size();i++) {
			CEntree::printTimeT(tempsRetardDepart[i]);
		}
	}
	static void AffecterTempsArrivee(vector<int> p_retardSecondes) {
		tempsRetardArrivee.resize(p_retardSecondes.size());
		for (unsigned int i = 0; i < tempsRetardDepart.size(); i++) {
			tempsRetardArrivee[i] =  p_retardSecondes[i];
		}

	}
};


