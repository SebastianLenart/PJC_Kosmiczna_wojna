#ifndef POCISKKULA_H
#define POCISKKULA_H

#include "pocisk.h"

class PociskKula: public Pocisk
{
public:
    PociskKula(int kier=0, bool own = true);
    void ustawGrafike();
    QPointF getPktKulaOgolny();

public slots:
//   void move();

};

#endif // POCISKKULA_H
