#include "czarnadziura.h"

CzarnaDziura::CzarnaDziura(QGraphicsItem *parent)
{
    ustawGrafike();

}

void CzarnaDziura::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/CzarnaDziura.png"));
}
