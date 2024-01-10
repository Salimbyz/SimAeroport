#include "CEVAvionDecolle.h"

CEVAvionDecolle::CEVAvionDecolle()
{
	avion = new CAvion();
	pisteDecollage = new CPisteDecollage();
}

CEVAvionDecolle::~CEVAvionDecolle()
{
	delete(avion);
	delete(pisteDecollage);
}

CEVAvionDecolle::CEVAvionDecolle(CAvion p_avion, CPisteDecollage p_pisteDecollage, time_t p_temps)
{
	avion = new CAvion(p_avion);
	pisteDecollage = new CPisteDecollage(p_pisteDecollage);
	this->ecrireTempsDebut(p_temps);
}
void CEVAvionDecolle::run() {

}