#include "ship.h"
#include <QDebug>

Ship::Ship(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/image/image/ShipBlue.png"));
}

void Ship::move(int kierunek)
{
    this->setTransformOriginPoint(ShipWidth/2, ShipHeight/2);
    switch(kierunek) {
    case 1: // W
        this->setPos(x(), y()-speed);
        this->setRotation(0);
        break;
    case 2: // A
        this->setPos(x()-speed, y());
        this->setRotation(270);
        break;
    case 3: // D
        this->setPos(x()+speed, y());
        this->setRotation(90);
        break;
    case 4: // S
        this->setPos(x(), y()+speed);
        this->setRotation(180);
        break;
    case 5: // Q
        this->setPos(x()-speed, y()-speed);
        this->setRotation(315);
        break;
    case 6: // E
        this->setPos(x()+speed, y()-speed);
        this->setRotation(45);
        break;
    case 7: // Z
        this->setPos(x()-speed, y()+speed);
        this->setRotation(225);
        break;
    case 8: // C
        this->setPos(x()+speed, y()+speed);
        this->setRotation(135);
        break;
    }
}
