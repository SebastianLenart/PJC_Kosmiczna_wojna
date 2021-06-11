#include "shipred.h"
#include "ship.h"
#include <QGraphicsScene>

#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pociskpodwojny.h"
#include <typeinfo>
#include "mglawica.h"
#include "tunel.h"
#include <QDebug>

ShipRed::ShipRed(int ktoryPoc, bool e)
{
    this->setPixmap(QPixmap(":/image/image/ShipRed.png"));
    speed = 7;
    Orginalspeed = speed;

    HP=10;
    IsEnemy = e;
    wyborBroni = ktoryPoc;
    czeststrzalow(1000); // co 3 s strzal
}

QPointF ShipRed::getPktShipOgolny()
{
    return getPktSrodek()+this->pos();
}

