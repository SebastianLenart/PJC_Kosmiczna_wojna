#include "bomba.h"

Bomba::Bomba(QString path,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    ustawGrafike(path);
}

void Bomba::ustawGrafike(QString path)
{
    this->setPixmap(QPixmap(path));
}

void Bomba::setSizePix(double w, double h)
{
    PixBombWidth = w;
    PixBombHeight = h;
}

QPointF Bomba::centerBomby()
{
    return QPointF(PixBombHeight/2, PixBombHeight/2);
}

QPointF Bomba::centerBombyOgolny()
{
    //    return QPointF(mapToScene(centerBomby())); // spr czy to dziala???
}
