#ifndef CZARNADZIURA_H
#define CZARNADZIURA_H

#include "zjawiska.h"

class CzarnaDziura: public Zjawiska
{
    Q_OBJECT
public:
    CzarnaDziura(QGraphicsItem* parent=0);
    void ustawGrafike();
};

#endif // CZARNADZIURA_H
