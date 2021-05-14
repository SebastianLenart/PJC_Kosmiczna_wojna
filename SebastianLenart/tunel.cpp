#include "tunel.h"

Tunel::Tunel(QGraphicsItem *parent)
{
    ustawGrafike();
    zmienPredkosc  = 15;
}

void Tunel::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/Tunel1.png"));
}

int Tunel::getPredkosc()
{
    return zmienPredkosc;
}
