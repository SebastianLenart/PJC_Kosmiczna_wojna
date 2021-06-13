#include "zjawiska.h"
#include <QPixmap>

Zjawiska::Zjawiska(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

}

void Zjawiska::setSizePix(double w, double h)
{
    PixHeight = h;
    PixWidth = w;
    setPointCenter(PixWidth, PixHeight);
}

void Zjawiska::ustawGrafike(QPixmap path) { }

void Zjawiska::setName(QString n)
{
    name = n;
}

void Zjawiska::setPointCenter(double a, double b)
{
    Center = QPointF(a/2, b/2);
}

double Zjawiska::getPixWidth()
{
    return PixWidth;
}

double Zjawiska::getPixHeight()
{
    return PixHeight;
}



