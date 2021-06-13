#include "pociskpodwojny.h"
#include <QDebug>

PociskPodwojny::PociskPodwojny(int kier, QPointF poz, int odl, bool own)
{
    kierunek = kier;
    ustawGrafike();
    PocWidth = 17;
    PocHeight = 59;
    setPointCenterObiekt(PocWidth, PocHeight);
    ustawKierunek(kierunek, PocWidth, PocHeight);
    predkosc = 20;
    dx = 7;
    ustawPoz(kier, poz, odl);
    IsEnemy = own;
    obrazenia = 3;
}

void PociskPodwojny::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/PocNaprowadzajacy.png"));
}

QPointF PociskPodwojny::getPktPodwOgolny()
{
    return getPktSrodek()+this->pos();
}

void PociskPodwojny::ustawPoz(int kierun, QPointF pozyc, int odle)
{
    if(kierun==0 || kierun==3) { // W i S
        this->setPos(pozyc-QPointF(this->getPktSrodek().x()-odle, this->getPktSrodek().y()));
    }
    if(kierun==1 || kierun==2) { // A i D
        this->setPos(pozyc-QPointF(this->getPktSrodek().x(), this->getPktSrodek().y()-odle));
    }
    if(kierun==4 || kierun==7) { // Q i C
        this->setPos(pozyc-QPointF(this->getPktSrodek().x()-odle, this->getPktSrodek().y()+odle));
    }
    if(kierun==5 || kierun==6) { // E i Z
        this->setPos(pozyc-QPointF(this->getPktSrodek().x()-odle, this->getPktSrodek().y()-odle));
    }

}
