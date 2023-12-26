#pragma once
#include "CEvenement.h"
class CEVAvionDecolle :
    public CEvenement
{
private :
    CPisteDecollage* pisteDecollage;
    CAvion* avion;
public :
    CEVAvionDecolle();
    CEVAvionDecolle(CEVAvionDecolle& p_EVAvionDecolle);
    ~CEVAvionDecolle();

    void ModifierAvion(CAvion p_avion) { *avion = p_avion; }
    void ModifierPisteDecollage(CPisteDecollage p_pisteDecollage) { *pisteDecollage = p_pisteDecollage; }
    CAvion LireAvion() { return *avion; }
    CPisteDecollage LirePisteDecollage() { return *pisteDecollage; }
    void run();

};

