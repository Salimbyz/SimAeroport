#include "CRessource.h"

CRessource::CRessource()
{
	occupe = false;
}

CRessource::CRessource(const CRessource& p_ressource)
{
	occupe = p_ressource.occupe;

}

CRessource::CRessource(bool p_occupe)
{
	occupe = p_occupe;
}

CRessource::~CRessource()
{
}

void CRessource::modifierOccupation(bool p_occupe)
{
	occupe = p_occupe;
}

bool CRessource::lireOccupation()
{
	return occupe;
}
