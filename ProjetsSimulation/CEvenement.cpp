#include "CEvenement.h"

CEvenement::CEvenement()
{
	tempsDebut = time(nullptr);
	tempsEvenement = time(nullptr);
}

CEvenement::CEvenement(CEvenement& p_evenement)
{
	tempsDebut = p_evenement.lireTempsDebut();
	tempsEvenement = p_evenement.lireTempsEvenement();
}


CEvenement::~CEvenement()
{
	tempsDebut = 0;
	tempsEvenement = 0;
}

void CEvenement::ecrireTempsDebut(time_t p_tempsDebut)
{
	tempsDebut = p_tempsDebut;
}

time_t CEvenement::lireTempsDebut()
{
	return tempsDebut;
}

void CEvenement::ecrireTempsEvenement(time_t p_tempsEvenement)
{
	tempsEvenement = p_tempsEvenement;
}

time_t CEvenement::lireTempsEvenement()
{
	return tempsEvenement;
}

 void CEvenement::run()
 {
	
 }