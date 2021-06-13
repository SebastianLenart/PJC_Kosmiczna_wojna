#ifndef SHIPRED_H
#define SHIPRED_H

#include "ship.h"

/**
 * @brief The ShipRed class
 * Klasa ShipRed i jej cechy indywidualne m. in.  ustawienie szybkosci, zycia (HP), czy to statek wroga, jaki pocisk posiada
 * \param ShipRed - konstruktor, w ktorym ustawia sie parametry tego obiektu
 * \param getPktKulaOgolny - zrwaca punkt przebywania kuli
 */


class ShipRed: public Ship
{
    Q_OBJECT
public:
    ShipRed(int ktoryPoc = 2, bool e = true);
    QPointF getPktShipOgolny();
};

#endif // SHIPRED_H
