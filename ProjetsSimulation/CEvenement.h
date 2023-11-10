#include <iostream>
#include "CAvion.h"
#include "CPisteAtterissage.h"
#include "CPisteDecollage.h"
#include <time.h>

class CEvenement
{
private:
    time_t tempsDebut;
    time_t tempsEvenement;
    

public:

    CEvenement();
    CEvenement(CEvenement& p_evenement);
    ~CEvenement();

    void ecrireTempsDebut(time_t p_tempsDebut);
    time_t lireTempsDebut();

    void ecrireTempsEvenement(time_t p_tempsEvenement);
    time_t lireTempsEvenement();

    void ecrireAvion(CAvion p_avion);
    CAvion lireAvion();
    void run();

};