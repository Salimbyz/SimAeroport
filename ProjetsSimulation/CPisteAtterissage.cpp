#include "CPisteAtterissage.h"

CPisteAtterissage::CPisteAtterissage()
{
	idPisteA = 0;
}

CPisteAtterissage::CPisteAtterissage(CPisteAtterissage& p_pisteA)
{
	idPisteA = p_pisteA.lireIdPisteA();
}

CPisteAtterissage::~CPisteAtterissage()
{
}

void CPisteAtterissage::ecrireIdPisteA(unsigned int p_idPisteA)
{
	idPisteA = p_idPisteA;
}

unsigned int CPisteAtterissage::lireIdPisteA()
{
	return idPisteA;
}
