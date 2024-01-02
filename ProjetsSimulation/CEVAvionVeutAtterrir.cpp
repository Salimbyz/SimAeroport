#include "CEVAvionVeutAtterrir.h"
#include "CEVAvionAtterrit.h"
CEVAvionVeutAtterrir::CEVAvionVeutAtterrir()
{
	pisteAtterissage = new CPisteAtterissage();
	avion = new CAvion();
}

CEVAvionVeutAtterrir::~CEVAvionVeutAtterrir()
{
	if (pisteAtterissage != NULL) {
		delete(pisteAtterissage);
	}
	if (avion != NULL) {
		delete(avion);
	}

}
void CEVAvionVeutAtterrir::run() {


}