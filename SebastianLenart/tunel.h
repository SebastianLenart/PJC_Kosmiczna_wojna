#ifndef TUNEL_H
#define TUNEL_H

#include "zjawiska.h"

class Tunel:public Zjawiska
{
    Q_OBJECT
public:
    Tunel(QGraphicsItem* parent=0);
    void ustawGrafike();
    int  getPredkosc();
};

#endif // TUNEL_H
