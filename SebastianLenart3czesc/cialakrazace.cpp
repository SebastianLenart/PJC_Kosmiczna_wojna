#include "cialakrazace.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>

CialaKrazace::CialaKrazace(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)//, nameCiala(nazwa)
{

}

void CialaKrazace::setName(QString nazwa)
{
    nameCiala = nazwa;
}

void CialaKrazace::setPointShine(int a, int b)
{
    PktSlonca = QPointF(a, b);
}

void CialaKrazace::setPointCenterObiekt(double a, double b)
{
    PktCenter = QPointF(a/2, b/2);
}

double CialaKrazace::getWidth()
{
    return PlWidht;
}

double CialaKrazace::getHeight()
{
    return PlHeight;
}

QPointF CialaKrazace::getPktSrodek()
{
    return PktCenter;
}

QPointF CialaKrazace::setDistance(double d, QGraphicsItem *obiekt) {}


void CialaKrazace::UstawGrafike(QString path) {}

void CialaKrazace::setSizeMap(double w, double h)
{
    PlWidht = w;
    PlHeight = h;
    setPointCenterObiekt(PlWidht, PlHeight);
}
