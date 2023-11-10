#include "CEvenement.h"

CEvenement::CEvenement()
{
	tempsDebut = time(nullptr);
	tempsEvenement = time(nullptr);
	avion = CAvion();
	PisteAtterissage = CPisteAtterissage();
	PisteDecollage = CPisteDecollage();
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

void CEvenement::ecrirePisteAtterissage(CPisteAtterissage p_pisteAtterissage)
{
	PisteAtterissage = CPisteAtterissage(p_pisteAtterissage);
}

CPisteAtterissage CEvenement::lirePisteAtterissage()
{
	return PisteAtterissage;
}

void CEvenement::ecrirePisteDecollage(CPisteDecollage p_pisteDecollage)
{
	PisteDecollage = CPisteDecollage(p_pisteDecollage);
}

CPisteDecollage CEvenement::lirePisteDecolalge()
{
	return PisteDecollage;
}

void CEvenement::ecrireAvion(CAvion p_avion)
{
	avion = CAvion(p_avion);
}

CAvion CEvenement::lireAvion()
{
	return avion;
}
 void CEvenement::run()
 {
	
 }