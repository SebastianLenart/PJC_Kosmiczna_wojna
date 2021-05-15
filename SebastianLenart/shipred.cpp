#include "shipred.h"
#include "ship.h"
#include <QGraphicsScene>

#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pocisknaprowadzajacy.h"

ShipRed::ShipRed(int ktoryPoc, bool e)
{
    this->setPixmap(QPixmap(":/image/image/ShipRed.png"));
    speed = 15;
    HP=10;
    IsEnemy = e;
    wyborBroni = ktoryPoc;
}

