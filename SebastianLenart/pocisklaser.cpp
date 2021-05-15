#include "pocisklaser.h"

PociskLaser::PociskLaser()
{
    ustawGrafike();
}

void PociskLaser::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/PocLaser.png"));
}
