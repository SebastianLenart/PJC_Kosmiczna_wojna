#include "bomba.h"
#include "wynik.h"
//#include "game.h" // powoduje blad
#include <QTimer>
#include <QDebug>


Bomba::Bomba(bool own)
{
    ustawGrafike();
    PocWidth = 84;
    PocHeight = 80;
    setPointCenterObiekt(PocWidth, PocHeight);
    noTouch = false;
    IsEnemy = own;
    wybuch = false;
    i=4;
    obrazenia = 1000;
}

void Bomba::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/bomba.png"));
}

QPointF Bomba::getPktBombaOgolny() // nie dziala zbytnio
{
    return getPktSrodek()+this->pos();
}

void Bomba::setTouch(bool a) // true
{
    noTouch = a;
}

bool Bomba::getTouch()
{
    return noTouch;
}

void Bomba::setPozycje(QPointF pkt)
{
    pozycja = pkt;
}

QPointF Bomba::getPozycje()
{
    return pozycja;

}

void Bomba::startOdliczania()
{
    odliczT = new QTimer();
    connect(odliczT, SIGNAL(timeout()), this, SLOT(odlF()));
    odliczT->start(1000);

    odlW = new Wynik();
    odlW->odliczanieBomby(i);
    odlW->setPos(pozycja);// to dziala
}

void Bomba::move()
{
    if(isDelete) return;
}

void Bomba::odlF()
{
    i--;
    if(i<0) {
        wybuch = true;
    } else {
        odlW->odliczanieBomby(i);
        odlW->setPos(pozycja);
    }

    if(i<=-1)
    {
        delete  this;
        delete  odlW;
        odliczT->stop();
        delete odliczT;
    }
}



