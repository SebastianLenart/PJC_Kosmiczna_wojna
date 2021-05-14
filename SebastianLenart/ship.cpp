#include "ship.h"
#include <QDebug>
#include <stdlib.h> // rand()
#include <time.h> // rand()

Ship::Ship(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //    this->setPixmap(QPixmap(":/image/image/ShipBlue.png"));
    //zasieg
    this->setTransformOriginPoint(ShipWidth/2, ShipHeight/2);
}

void Ship::move(int kierunek)
{

    switch(kierunek) {
    case 0: // W
        if(this->pos().y()>0) {
            this->setPos(x(), y()-speed);
            this->setRotation(0);
        }
        break;
    case 1: // A
        if(this->pos().x()>30) {
            this->setPos(x()-speed, y());
            this->setRotation(270);
        }
        break;
    case 2: // D
        if(this->pos().x()<1400) {
            this->setPos(x()+speed, y());
            this->setRotation(90);
        }
        break;
    case 3: // S
        if(this->pos().y()<850) {
            this->setPos(x(), y()+speed);
            this->setRotation(180);
        }
        break;
    case 4: // Q
        if(this->pos().x()>30 && this->pos().y()>0) {
            this->setPos(x()-speed, y()-speed);
            this->setRotation(315);
        }
        break;
    case 5: // E
        if(this->pos().x()<1400 && this->pos().y()>0) {
            this->setPos(x()+speed, y()-speed);
            this->setRotation(45);
        }
        break;
    case 6: // Z
        if(this->pos().x()>30 && this->pos().y()<850) {
            this->setPos(x()-speed, y()+speed);
            this->setRotation(225);
        }
        break;
    case 7: // C
        if(this->pos().x()<1400 && this->pos().y()<850) {
            this->setPos(x()+speed, y()+speed);
            this->setRotation(135);
        }
        break;
    }
    qDebug()<<this->pos().y();
}

void Ship::moveRand(int k)
{
    //    int randNr = rand()%9;
    move(k);
}
