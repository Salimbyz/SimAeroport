#include <iostream>
#include "CAvion.h"
#include "CPisteAtterissage.h"
#include "CPisteDecollage.h"
#include <time.h>

class CEvenement
{
private:
    time_t tempsDebut;
    

public:

    CEvenement();
    CEvenement(CEvenement& p_evenement);
    ~CEvenement();

    void ecrireTempsDebut(time_t p_tempsDebut);
    time_t lireTempsDebut();

    void ecrireTempsEvenement(time_t p_tempsEvenement);
    time_t lireTempsEvenement();

    void run();

};