#include "shipblue.h"
#include "ship.h"

#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pocisknaprowadzajacy.h"

ShipBlue::ShipBlue(int ktoryPoc, bool e)
{
    this->setPixmap(QPixmap(":/image/image/ShipBlue.png"));
    speed = 5;
    HP = 5;
    IsEnemy = e;
    wyborBroni = ktoryPoc;
}

