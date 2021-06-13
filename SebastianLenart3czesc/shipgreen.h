#ifndef SHIPGREEN_H
#define SHIPGREEN_H

#include "ship.h"


/**
 * @brief The ShipGreen class
 *  * Klasa ShipGreen i jej cechy indywidualne m. in.  ustawienie szybkosci, zycia (HP), czy to statek wroga, jaki pocisk posiada
 * \param ShipGreen - konstruktor, w ktorym ustawia sie parametry tego obiektu
 * \param getPktKulaOgolny - zrwaca punkt przebywania kuli
 */

class ShipGreen: public Ship
{
    Q_OBJECT
public:
    ShipGreen(int ktoryPoc = 1, bool e = true);
    QPointF getPktShipOgolny();
};

#endif // SHIPGREEN_H
