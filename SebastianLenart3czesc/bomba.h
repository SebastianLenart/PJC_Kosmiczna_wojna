#ifndef BOMBA_H
#define BOMBA_H

#include "pocisk.h"

class Bomba: public Pocisk
{
public:
    Bomba(bool own = true);
    void ustawGrafike();
    QPointF getPktBombaOgolny();
    void setTouch(bool a);
    bool getTouch();

public slots:
   void move();

private:
   bool noTouch;

};

#endif // BOMBA_H
