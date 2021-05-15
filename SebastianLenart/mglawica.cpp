#include "mglawica.h"

Mglawica::Mglawica(bool b, QGraphicsItem *parent)
{
    ustawGrafike(b);
    zmienPredkosc = 3;
}

void Mglawica::ustawGrafike(bool f)
{
    if(f) {
        this->setPixmap(QPixmap(":/image/image/Mglawica1.png"));
    } else this->setPixmap(QPixmap(":/image/image/Mglawica2.png"));

}

int Mglawica::getPredkosc()
{
    return zmienPredkosc;
}
