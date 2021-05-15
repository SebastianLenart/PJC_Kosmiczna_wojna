#ifndef SHIPRED_H
#define SHIPRED_H

#include "ship.h"

class ShipRed: public Ship
{
    Q_OBJECT
public:
    ShipRed(int ktoryPoc = 2, bool e = true);
};

#endif // SHIPRED_H
