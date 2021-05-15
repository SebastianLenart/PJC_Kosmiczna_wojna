#include "pociskkula.h"

PociskKula::PociskKula()
{

    ustawGrafike();
}

void PociskKula::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/PocKula.png"));
}
