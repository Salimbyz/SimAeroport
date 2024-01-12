#include "CEvenement.h"
#include "CEntree.h"
CEvenement::CEvenement()
{
	tempsDebut = time(nullptr);
}

CEvenement::CEvenement(CEvenement& p_evenement)
{
	tempsDebut = p_evenement.lireTempsDebut();
}


CEvenement::~CEvenement()
{
	tempsDebut = 0;
}

void CEvenement::ecrireTempsDebut(time_t p_tempsDebut)
{
	tempsDebut = p_tempsDebut;
}

time_t CEvenement::lireTempsDebut()
{
	return tempsDebut;
}

 void CEvenement::run()
 {
	
 }