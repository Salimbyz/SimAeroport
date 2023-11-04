#pragma once
#include <iostream>
#include <time.h>

class CAvion
{
private:
	unsigned int idAvion;
	static int nbAvion;

public:

	CAvion();
	CAvion(CAvion& p_avion);
	~CAvion();

	void modifierIdAvion(int p_idAvion);
	unsigned int lireIdAvion();

	void modifierNbAvion(static int p_nbAvion);
	static int lireNbAvion();
};