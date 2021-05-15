#include "ship.h"
#include <QDebug>
#include <stdlib.h> // rand()
#include <time.h> // rand()
#include <QTimer>
#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pocisknaprowadzajacy.h"

Ship::Ship(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    this->setTransformOriginPoint(ShipWidth/2, ShipHeight/2);

    //poniższe nie zadziala jak chce
    //    PociskKula* Kula = new PociskKula();
    //    VecPoc.append(Kula);

    //    PociskLaser* Laser = new PociskLaser();
    //    VecPoc.append(Laser);

    //    PociskNaprowadzajacy* PocNapr = new PociskNaprowadzajacy();
    //    VecPoc.append(PocNapr);

    QTimer* CheckLife = new QTimer();
    connect(CheckLife, SIGNAL(timeout()), this, SLOT(checkLifeShip()));
    CheckLife->start(100);
    IsDelete = false;
}

void Ship::move(int kierunek)
{
    obecnyKierunek = kierunek;
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
}

void Ship::zmienBron()
{
    wyborBroni++;
    if(wyborBroni>2) wyborBroni=0;
}

void Ship::setusunStatek(bool a)
{
    IsDelete = a;
}

bool Ship::getusunStatek()
{
    return IsDelete;
}

void Ship::strzal(int wyborbroni)
{
    qDebug()<<wyborbroni<<"strzal";
    switch (wyborbroni) {
    case 0: ;
    case 1: ;
    case 2: ;
    }
}

int Ship::getBron()
{
    return wyborBroni;
}

void Ship::checkLifeShip()
{
    if(this->HP<0) {
        if(!(this->IsEnemy)) {
            //przegrana
        } else {
            setusunStatek(true);
        }
    }
}

//zjawiska : int obrazenia -> get...
// ship dekerermentacja HP..

