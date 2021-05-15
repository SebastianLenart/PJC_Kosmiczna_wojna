#include "pocisknaprowadzajacy.h"

PociskNaprowadzajacy::PociskNaprowadzajacy()
{
    ustawGrafike();
}

void PociskNaprowadzajacy::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/PocNaprowadzajacy.png"));
}
