#ifndef MGLAWICA_H
#define MGLAWICA_H

#include "zjawiska.h"

class Mglawica: public Zjawiska
{
    Q_OBJECT
public:
    Mglawica(bool b=true, QGraphicsItem* parent=0);
    void ustawGrafike(bool f);
    int getPredkosc();
};

#endif // MGLAWICA_H
