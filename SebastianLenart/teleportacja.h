#ifndef TELEPORTACJA_H
#define TELEPORTACJA_H

#include "zjawiska.h"

class Teleportacja:public Zjawiska {
    Q_OBJECT

public:
    Teleportacja(QString name, bool b = true, QGraphicsItem* parent=0);
    void ustawGrafike(bool f=true);
};

#endif // TELEPORTACJA_H
