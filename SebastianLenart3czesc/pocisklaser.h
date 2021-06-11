#ifndef POCISKLASER_H
#define POCISKLASER_H

#include "pocisk.h"

class PociskLaser: public Pocisk
{
public:
    PociskLaser(int kier, bool own);
    void ustawGrafike();
    QPointF getPktLaserOgolny();

public slots:

};

#endif // POCISKLASER_H
