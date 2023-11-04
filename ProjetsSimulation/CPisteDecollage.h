#pragma once
class CPisteDecollage
{
private: 
	unsigned int idPisteD;

public :
	CPisteDecollage();
	CPisteDecollage(CPisteDecollage& p_pisteD);
	~CPisteDecollage();

	void ecrireIdPisteD(unsigned int p_idPisteD);
	unsigned int lireIdPisteD();
};

