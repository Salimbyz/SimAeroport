#include "CRessource.h"

CRessource::CRessource()
{
	occupe = false;
}

CRessource::CRessource(CRessource& p_ressource)
{
	occupe = p_ressource.lireOccupation();

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
