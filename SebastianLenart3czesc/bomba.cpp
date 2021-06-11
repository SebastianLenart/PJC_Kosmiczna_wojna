#include "bomba.h"

Bomba::Bomba(bool own)
{
    ustawGrafike();
    PocWidth = 84;
    PocHeight = 80;
    setPointCenterObiekt(PocWidth, PocHeight);
    noTouch = false;
    IsEnemy = own;
}

void Bomba::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/bomba.png"));
}

QPointF Bomba::getPktBombaOgolny()
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

void Bomba::move()
{

}














//void Bomba::setSizePix(double w, double h)
//{
//    PixBombWidth = w;
//    PixBombHeight = h;
//}

//QPointF Bomba::centerBomby()
//{
//    return QPointF(PixBombHeight/2, PixBombHeight/2);
//}

//QPointF Bomba::centerBombyOgolny()
//{
//    //    return QPointF(mapToScene(centerBomby())); // spr czy to dziala???
//}
