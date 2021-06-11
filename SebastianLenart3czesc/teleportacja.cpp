#include "teleportacja.h"

Teleportacja::Teleportacja(QString name, bool b, QGraphicsItem *parent)
{
    ustawGrafike(b);
    setName(name);
}

void Teleportacja::ustawGrafike(bool f)
{
    if(f) {
        this->setPixmap(QPixmap(":/image/image/TeleFiol.png"));
    } else this->setPixmap(QPixmap(":/image/image/TepePom.png"));
}
