#include "CEVAvionDecolle.h"
#include "CEVAvionQuitteAeroport.h"

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

CEVAvionDecolle::CEVAvionDecolle(CAvion p_avion, CPisteDecollage* p_pisteDecollage, time_t p_temps)
{
	avion = new CAvion(p_avion);
	pisteDecollage = p_pisteDecollage;
	this->ecrireTempsDebut(p_temps);
}
void CEVAvionDecolle::run() {
	std::cout << "avion n " << avion->lireIdAvion() << " decolle" << std::endl;
	CEVAvionQuitteAeroport EVAQA(*avion,pisteDecollage,this->lireTempsDebut()+300);
	EVAQA.run();
}