#ifndef SHIPBLUE_H
#define SHIPBLUE_H

#include "ship.h"

class ShipBlue : public Ship
{
    Q_OBJECT
public:
    ShipBlue(int ktoryPoc = 0, bool e = true);
    QPointF getPktShipOgolny();
};

#endif // SHIPBLUE_H
