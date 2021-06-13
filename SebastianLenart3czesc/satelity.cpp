#include "satelity.h"
#include "planety.h"
#include "cialakrazace.h"
#include <QDebug>
#include <QTimer>

Satelity::Satelity(QGraphicsItem *parent)
{

}

Satelity::Satelity(QPixmap path, unsigned int czasOsi, Planety* Ow,QGraphicsItem *parent)
{
    UstawGrafike(path);
    setOwner(Ow);
    setTimer(czasOsi);

    //ustaw timer aktualizacji pobierania pozycji ziemi oraz ustawiaj pos satelity
}

void Satelity::UstawGrafike(QPixmap path)
{
    this->setPixmap(path);
}

QPointF Satelity::getPktSatelityOgolny()
{
    return getPktSrodek()+this->pos();
}

QPointF Satelity::setDistance(double d, Planety *obiekt, bool pozycja)
{
    dystans=d;
    pozSat=pozycja;
    int poz=1;
    if(pozycja) poz=1;
    else poz=-1;

    QLineF dystans (QPointF(obiekt->getPktPlanetyOgolny().x() + poz*d,obiekt->getPktPlanetyOgolny().y()), obiekt->getPktPlanetyOgolny());
//    qDebug() <<dystans.p1()<<dystans.p2()<<this->pos()<<obiekt->pos();
    return QPointF(dystans.p1()-getPktSrodek());
}

void Satelity::setOwner(Planety* Ow)
{
    this->Owner = Ow;
}

void Satelity::setTimer(unsigned int czas)
{
    TimerRot = czas;
    QTimer* RotSat = new QTimer();
    connect(RotSat, SIGNAL(timeout()), this, SLOT(rotacja()));
    RotSat->start(TimerRot);


}

void Satelity::rotacja()
{
    this->setPos(setDistance(dystans,Owner,pozSat));
}
