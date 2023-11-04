#pragma once
#include <iostream>
#include <time.h>
class CPisteAtterissage
{
private:
	unsigned int idPisteA;

public:
	CPisteAtterissage();
	CPisteAtterissage(CPisteAtterissage& p_pisteA);
	~CPisteAtterissage();

	void ecrireIdPisteA(unsigned int p_idPisteA);
	unsigned int lireIdPisteA();
};

