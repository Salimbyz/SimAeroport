#pragma once
#include "CEvenement.h"
#include "CPorteEmbarquement.h"
class CEVAvionQuitteGate :
    public CEvenement
{
private:
    CPorteEmbarquement* gate;
    CAvion* avion;
public :
    CEVAvionQuitteGate();
    CEVAvionQuitteGate(CAvion p_avion, CPorteEmbarquement p_gate);
    ~CEVAvionQuitteGate();
    CEVAvionQuitteGate(CEVAvionQuitteGate& p_EVQG);

    CAvion LireAvion() { return *avion; }
    CPorteEmbarquement LireGate() { return *gate; }

    
};

