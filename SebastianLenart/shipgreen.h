#ifndef SHIPGREEN_H
#define SHIPGREEN_H

#include "ship.h"

class ShipGreen: public Ship
{
    Q_OBJECT
public:
    ShipGreen(int ktoryPoc = 1, bool e = true);
};

#endif // SHIPGREEN_H
