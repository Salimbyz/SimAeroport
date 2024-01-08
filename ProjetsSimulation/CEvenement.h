#include <iostream>
#include "CAvion.h"
#include "CPisteAtterissage.h"
#include "CPisteDecollage.h"
#include "CPorteEmbarquement.h"
#include <time.h>
#ifndef CEvenement_H
#define CEvenement_H


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

    void run();

};
#endif // !CEvenement_H
