#pragma once
#include "CEvenement.h"
class CEVAvionVeutDecoller :
    public CEvenement
{
private:
    static vector<CPisteDecollage> pistesDecollage;
    CAvion* avion;
public:
    CEVAvionVeutDecoller();
    ~CEVAvionVeutDecoller();
    CEVAvionVeutDecoller(CAvion p_avion, time_t p_temps);

    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }
    void ModifierPisteDecollage(vector<CPisteDecollage> p_pisteDecollage) { pistesDecollage = p_pisteDecollage; }
    CAvion LireAvion() { return *avion; }
    vector<CPisteDecollage> LirePisteDecollage() { return pistesDecollage; }
    static void AjouterPiste(CPisteDecollage p_pisteD) { pistesDecollage.push_back(p_pisteD); }
    void run();

};

