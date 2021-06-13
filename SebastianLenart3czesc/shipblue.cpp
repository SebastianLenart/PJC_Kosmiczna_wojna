#include "shipblue.h"
#include "ship.h"

#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pociskpodwojny.h"

ShipBlue::ShipBlue(int ktoryPoc, bool e)
{
    this->setPixmap(QPixmap(":/image/image/ShipBlue.png"));
    speed = 5;
    Orginalspeed = speed;

    HP = 5;
    IsEnemy = e;
    wyborBroni = ktoryPoc;
    czeststrzalow(3000);
}

QPointF ShipBlue::getPktShipOgolny()
{
    return getPktSrodek()+this->pos();
}

