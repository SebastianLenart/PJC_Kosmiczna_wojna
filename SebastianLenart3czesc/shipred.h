#ifndef SHIPRED_H
#define SHIPRED_H

#include "ship.h"

class ShipRed: public Ship
{
    Q_OBJECT
public:
    ShipRed(int ktoryPoc = 2, bool e = true);
    QPointF getPktShipOgolny();
//    void kolizje();
};

#endif // SHIPRED_H
