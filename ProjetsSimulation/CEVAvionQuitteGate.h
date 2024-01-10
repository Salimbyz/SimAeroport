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
    CEVAvionQuitteGate(CAvion p_avion, CPorteEmbarquement p_gate, time_t p_temps);
    ~CEVAvionQuitteGate();

    CAvion LireAvion() { return *avion; }
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }

    CPorteEmbarquement LireGate() { return *gate; }
    void ModifierPorteEmbarquement(CPorteEmbarquement p_gate) { *gate = p_gate; }

    void run();

    
};

