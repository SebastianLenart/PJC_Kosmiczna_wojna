#include "ship.h"
#include <QDebug>
#include <stdlib.h> // rand()
#include <time.h> // rand()
#include <QTimer>
#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pociskpodwojny.h"
#include "bomba.h"
#include "game.h"
#include <typeinfo>
#include "mglawica.h"
#include "tunel.h"
#include "czarnadziura.h"
#include <QGraphicsTextItem>
#include <QFont>

extern Game* game;

Ship::Ship(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{

    this->setTransformOriginPoint(ShipWidth/2, ShipHeight/2);
    setPointCenterObiekt(ShipWidth, ShipHeight);

    QTimer* CheckLife = new QTimer();
    connect(CheckLife, SIGNAL(timeout()), this, SLOT(checkLifeShip()));
    CheckLife->start(100);
    IsDelete = false;
    iloscBroni = 2; // po dotknieciu bomby => 3;
    setusunStatek(false); // ustawiam statek na jeszcze nie usuniety

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
    // kolizje w ruchu
    kolizje();

}

void Ship::zmienBron()
{
    wyborBroni++;
    if(wyborBroni>iloscBroni) wyborBroni=0;
}

void Ship::setusunStatek(bool a)
{
    IsDelete = a;
}

bool Ship::getusunStatek()
{
    return IsDelete;
}

void Ship::strzal(int wyborbroni, QPointF pozycja) {
    switch (wyborbroni) {
    case 0:
        if(IsEnemy) bullet = new PociskKula(this->obecnyKierunek, true); // nwm czemu nie moge dac Pocisk* test...?
        if(!IsEnemy) bullet = new PociskKula(this->obecnyKierunek, false);

        bullet->setPos(pozycja-bullet->getPktSrodek());
        game->scenaGra->addItem(bullet);
        break;
    case 1:
        if(IsEnemy) bullet = new PociskLaser(this->obecnyKierunek, true);
        if(!IsEnemy) bullet = new PociskLaser(this->obecnyKierunek, false);

        bullet->setPos(pozycja-bullet->getPktSrodek());
        game->scenaGra->addItem(bullet);
        break;
    case 2:

        if(IsEnemy) bullet = new PociskPodwojny(this->obecnyKierunek, pozycja, 25, true);
        if(!IsEnemy) bullet = new PociskPodwojny(this->obecnyKierunek, pozycja, 25, false);
        game->scenaGra->addItem(bullet);

        if(IsEnemy) bullet = new PociskPodwojny(this->obecnyKierunek, pozycja, -25, true);
        if(!IsEnemy) bullet = new PociskPodwojny(this->obecnyKierunek, pozycja, -25, false);
        game->scenaGra->addItem(bullet);
        break;
    case 3:
        if(IsEnemy) bomba = new Bomba(true);
        if(!IsEnemy) bomba = new Bomba(false);
        bomba->setPos(pozycja-bomba->getPktSrodek());
        bomba->setPozycje(bomba->pos());  // ustawie zegar na bombie
        bomba->startOdliczania();
        bomba->setTouch(true);
        game->scenaGra->addItem(bomba);
        game->scenaGra->addItem(bomba->odlW);
        break;
    }
}

int Ship::getBron()
{
    return wyborBroni;
}


void Ship::checkLifeShip()
{
    aktualizacja();

    if(this->HP<0) {
        if(!(this->IsEnemy)) {
            //przegrana
            game->gameover(QString("Przegrana"));
        } else {
            setusunStatek(true);
        }
    }
}

void Ship::czeststrzalow(int a) // dla boota
{
    CzestotliwoscStrzalowBoota = a;
}

void Ship::kolizje()
{
    QList<QGraphicsItem*> items = collidingItems();
    for(int i=0; i<items.size(); i++) {
        if(typeid(*items[i]) == typeid(Mglawica)) {
            speed=2;
        }
        if(typeid(*items[i]) == typeid(Tunel)) {
            speed=25;
        }
        if((typeid(*items[i]) == typeid(Bomba))) {
            Bomba* bom = dynamic_cast<Bomba*>(items[i]); // rzutowanie aby dostac sie do metody bomby
            if(bom->getTouch() == false) {
                game->scenaGra->removeItem(bom);
                delete bom;
            }
            if(!IsEnemy) {
                iloscBroni = 3;
            }
        }
    }
    if(items.size()==0) {
        speed=Orginalspeed;
    }
}

void Ship::aktualizacja()
{
    QList<QGraphicsItem*> items = collidingItems();
    for(int i=0; i<items.size(); i++) {
        if(typeid(*items[i]) == typeid(PociskKula) || typeid(*items[i]) == typeid(PociskPodwojny) || typeid(*items[i]) == typeid(PociskLaser) || typeid(*items[i]) == typeid(Bomba)) {
            Pocisk* poc = dynamic_cast<Pocisk*>(items[i]);
            if((poc->getIsEnemy() != IsEnemy) && active) {
                HP=HP-poc->getObrazenia();
            }
        }
        if(typeid(*items[i]) == typeid (CzarnaDziura)){
            HP = -10;
        }
    }
}



void Ship::setPointCenterObiekt(double a, double b)
{
    PktCenter = QPointF(a/2, b/2);
}

QPointF Ship::getPktSrodek()
{
    return PktCenter;
}

QPointF Ship::getPktShipOgolny() { }

int Ship::getCzestStrzalow()
{
    return CzestotliwoscStrzalowBoota;
}

void Ship::setActive(bool a)
{
    active = a;
}

bool Ship::getActive()
{
    return active;
}

void Ship::setSpeed(int s)
{
    speed = s;
    Orginalspeed = speed;
}

int Ship::getSpeed()
{
    return speed;
}

double Ship::getHP()
{
    return HP;
}

QString Ship::getStrBron()
{
    if(wyborBroni==0) return "Kula";
    if(wyborBroni==1) return "Laser";
    if(wyborBroni==2) return "Podwojna";
    if(wyborBroni==3) return "Bomba";
}

void Ship::teleport()
{
    QList<QGraphicsItem*> items = collidingItems();
    for(int i=0; i<items.size(); i++) {
        if(typeid(*items[i]) == typeid(Teleportacja)) {
            Teleportacja* tele = dynamic_cast<Teleportacja*>(items[i]);
                setPos(tele->getPozDrugiego());
        }
    }
}






