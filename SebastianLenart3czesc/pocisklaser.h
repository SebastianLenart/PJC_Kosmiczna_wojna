#ifndef POCISKLASER_H
#define POCISKLASER_H

#include "pocisk.h"


/**
 * @brief The PociskLaser class
 *  * Klasa PociskLaser i jej cechy indywidualne
 * \param LaserKula - konstruktor, w ktorym ustawia sie parametry tego obiektu
 * \param ustawGrafike - ustawienie grafiki obiektu
 * \param getPktKulaOgolny - zrwaca punkt przebywania kuli
 */

class PociskLaser: public Pocisk
{
public:
    PociskLaser(int kier, bool own);
    void ustawGrafike();
    QPointF getPktLaserOgolny();

public slots:

};

#endif // POCISKLASER_H
