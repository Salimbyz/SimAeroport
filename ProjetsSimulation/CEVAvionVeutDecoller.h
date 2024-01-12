#pragma once
#include "CEvenement.h"
class CEVAvionVeutDecoller :
    public CEvenement
{
private:
    static vector<CPisteDecollage*> pistesDecollage;
    CAvion* avion;
public:
    CEVAvionVeutDecoller();
    ~CEVAvionVeutDecoller();
    CEVAvionVeutDecoller(CAvion p_avion, time_t p_temps);
    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }
    CAvion LireAvion() { return *avion; }
    vector<CPisteDecollage*> LirePisteDecollage() { return pistesDecollage; }
    static void AjouterPiste(CPisteDecollage p_pisteD) { 
        CPisteDecollage* pisteD = new CPisteDecollage(p_pisteD);
        pistesDecollage.push_back(pisteD); }
    void run();

};

