#include "shipgreen.h"
#include "ship.h"

#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pociskpodwojny.h"

ShipGreen::ShipGreen(int ktoryPoc, bool e)
{
    this->setPixmap(QPixmap(":/image/image/ShipGreen.png"));
    speed = 6;
    Orginalspeed = speed;

    HP=7;
    IsEnemy = e;
    wyborBroni = ktoryPoc;
    czeststrzalow(2000); // co 4 s strzal
}

QPointF ShipGreen::getPktShipOgolny()
{
    return getPktSrodek()+this->pos();
}
