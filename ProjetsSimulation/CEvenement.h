#include <iostream>
#include "CAvion.h"
#include "CPisteAtterissage.h"
#include "CPisteDecollage.h"
#include <time.h>

class CEvenement
{
private:
    time_t tempsDebut;
    CAvion avion;
    CPisteAtterissage PisteAtterissage;
    CPisteDecollage PisteDecollage;
    time_t tempsEvenement;


public:

    CEvenement();
    CEvenement(CEvenement& CEvent1);
    ~CEvenement();
};