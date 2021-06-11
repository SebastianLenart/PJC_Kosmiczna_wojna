#include "player.h"
#include "ship.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include "ship.h"
#include "shipblue.h"
#include "shipgreen.h"
#include "shipred.h"
#include <QKeyEvent>
#include <QDebug>
#include "wynik.h"
#include "game.h"

extern Game* game;

Player::Player(int w,QGraphicsItem* parent)
{
    switch(w) {
    case 1:
        ship = new ShipRed(false);
        break;
    case 2:
        ship = new ShipGreen(false);
        break;
    case 3:
        ship = new ShipBlue(false);
        break;
    }
    this->setPixmap(QPixmap(":/image/image/HOME.png"));
    this->setPos(1360, 840);
    ship->setPos(1360, 840);
    ship->IsEnemy = false; // musi byc bo poprzednie nie dzialalo
    ship->setActive(true);
    ship->setSpeed(15);
    this->stackBefore(ship);

    wynPlayera = new Wynik();
    wynPlayera->danePlayera(ship->getHP(), ship->getStrBron());
    wynPlayera->setPos(1300, 740);
    game->scenaGra->addItem(wynPlayera);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W) {
        ship->move(0);
    } else if(event->key() == Qt::Key_A) {
        ship->move(1);
    } else if(event->key() == Qt::Key_D) {
        ship->move(2);
    }  else if(event->key() == Qt::Key_S) {
        ship->move(3);
    }  else if(event->key() == Qt::Key_Q) {
        ship->move(4);
    }  else if(event->key() == Qt::Key_E) {
        ship->move(5);
    }  else if(event->key() == Qt::Key_Z) {
        ship->move(6);
    }  else if(event->key() == Qt::Key_C) {
        ship->move(7);
    }  else if(event->key() == Qt::Key_Space) {
        ship->strzal(ship->getBron(), ship->getPktShipOgolny()); // 2 argument to pkt pozycji
    }  else if(event->key() == Qt::Key_T) { // teleportacja
        //funkcja
    }  else if (event->key() == Qt::Key_M) {
        ship->zmienBron();
    }
    wynPlayera->danePlayera(ship->getHP(), ship->getStrBron());
}
