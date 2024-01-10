#include "CEVAvionVeutDecoller.h"

CEVAvionVeutDecoller::CEVAvionVeutDecoller()
{
	avion = new CAvion();
	pistesDecollage = vector<CPisteDecollage*>();
}

CEVAvionVeutDecoller::~CEVAvionVeutDecoller()
{
	delete(avion);

}

