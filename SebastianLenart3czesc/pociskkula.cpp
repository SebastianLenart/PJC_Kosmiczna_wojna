#include "pociskkula.h"
#include <QDebug>

PociskKula::PociskKula(int kier, bool own)
{
    kierunek = kier;
    ustawGrafike();
    PocWidth = 41;
    PocHeight = 43;
    setPointCenterObiekt(PocWidth, PocHeight);
    ustawKierunek(kierunek, PocWidth, PocHeight);
    predkosc = 70;
    dx = 3;
    IsEnemy = own;
    obrazenia = 1;
}

void PociskKula::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/PocKula.png"));
}

QPointF PociskKula::getPktKulaOgolny()
{
    return getPktSrodek()+this->pos();
}

//void PociskKula::move()
//{
//    this->setPos(x()+1, y());
//    usunPozaEkranem();
//}
