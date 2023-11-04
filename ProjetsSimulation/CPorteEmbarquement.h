#pragma once
class CPorteEmbarquement
{
private :
	unsigned int idPorteE;
public :
	CPorteEmbarquement();
	CPorteEmbarquement(CPorteEmbarquement& p_porteE);
	~CPorteEmbarquement();

	void ecrireIdPorteE(unsigned int p_idPorteE);
	unsigned int lireIdPorteE();
};

