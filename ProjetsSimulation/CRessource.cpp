#include "CRessource.h"

CRessource::CRessource()
{
	occupe = false;
	listeAttente = nullptr;
}

CRessource::CRessource(CRessource& p_ressource)
{
	occupe = p_ressource.lireOccupation();

}

CRessource::~CRessource()
{
	listeAttente = nullptr;
}

void CRessource::modifierOccupation(bool p_occupe)
{
	occupe = p_occupe;
}

bool CRessource::lireOccupation()
{
	return occupe;
}

void CRessource::modifierListeAttente(CAvion* p_listeAttente)
{
	for (int i = 0; i < sizeof(p_listeAttente); i++) {
		listeAttente[i] = p_listeAttente[i];
	}

}

CAvion* CRessource::lireListeAttente()
{
	return nullptr;
}
