#pragma once
#include "CEvenement.h"
class CEVAvionQuitteAeroport :
    public CEvenement
{
private: 
    CPisteDecollage* pisteDecollage;
    CAvion* avion;
public:
    CEVAvionQuitteAeroport();
    CEVAvionQuitteAeroport(CAvion p_avion, CPisteDecollage* p_pisteD, time_t p_temps);
    ~CEVAvionQuitteAeroport();
    CPisteDecollage LirePisteDecollage() { return *pisteDecollage; }
    void ModifierPisteDecollage(CPisteDecollage p_pisted){}
    CAvion LireAvion() { return *avion; }
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }
    void run();
};

