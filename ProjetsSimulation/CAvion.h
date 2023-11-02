#pragma once
#include <iostream>
#include <time.h>

class CAvion
{
private:
	int idAvion;
	static int nbAvion;
public:
	CAvion();
	CAvion(CAvion& Avion1);
	~CAvion();

};