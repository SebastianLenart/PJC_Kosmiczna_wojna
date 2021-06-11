#include "pocisklaser.h"

PociskLaser::PociskLaser(int kier, bool own = true)
{
    kierunek = kier;
    ustawGrafike();
    PocWidth = 65;
    PocHeight = 68;
    setPointCenterObiekt(PocWidth, PocHeight);
    ustawKierunek(kierunek, PocWidth, PocHeight);
    predkosc = 40;
    dx = 7;
    IsEnemy = own;
    obrazenia = 2;
}

void PociskLaser::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/PocLaser.png"));
}

QPointF PociskLaser::getPktLaserOgolny()
{
    return getPktSrodek()+this->pos();
}
