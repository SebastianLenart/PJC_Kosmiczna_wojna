#ifndef POCISKPODWOJNY_H
#define POCISKPODWOJNY_H

#include "pocisk.h"

class PociskPodwojny: public Pocisk
{
public:
    PociskPodwojny(int kier, QPointF poz, int odl, bool own = true);
    void ustawGrafike();
    QPointF getPktPodwOgolny();

public slots:
//   void move();
private:
    void ustawPoz(int kierun, QPointF pozyc , int odle);
};

#endif // POCISKPODWOJNY_H
