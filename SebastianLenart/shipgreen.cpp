#include "shipgreen.h"
#include "ship.h"

#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pocisknaprowadzajacy.h"

ShipGreen::ShipGreen(int ktoryPoc, bool e)
{
    this->setPixmap(QPixmap(":/image/image/ShipGreen.png"));
    speed = 10;
    HP=7;
    IsEnemy = e;
    wyborBroni = ktoryPoc;
}
