#ifndef SHIPBLUE_H
#define SHIPBLUE_H

#include "ship.h"


/**
 * @brief The ShipBlue class
 *  * Klasa ShipBlue i jej cechy indywidualne m. in.  ustawienie szybkosci, zycia (HP), czy to statek wroga, jaki pocisk posiada
 * \param ShipBlue - konstruktor, w ktorym ustawia sie parametry tego obiektu
 * \param getPktKulaOgolny - zrwaca punkt przebywania kuli
 */

class ShipBlue : public Ship
{
    Q_OBJECT
public:
    ShipBlue(int ktoryPoc = 0, bool e = true);
    QPointF getPktShipOgolny();
};

#endif // SHIPBLUE_H
