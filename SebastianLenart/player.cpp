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


Player::Player(QGraphicsItem* parent)
{
    ship = new Ship();
    this->setPixmap(QPixmap(":/image/image/HOME.png"));
    this->setPos(1360, 840);
    ship->setPos(1360, 840);
    this->stackBefore(ship);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"SD";
    if(event->key() == Qt::Key_W) {
        ship->move(1);
    } else if(event->key() == Qt::Key_A) {
        ship->move(2);
    } else if(event->key() == Qt::Key_D) {
        ship->move(3);
    }  else if(event->key() == Qt::Key_S) {
        ship->move(4);
    }  else if(event->key() == Qt::Key_Q) {
        ship->move(5);
    }  else if(event->key() == Qt::Key_E) {
        ship->move(6);
    }  else if(event->key() == Qt::Key_Z) {
        ship->move(7);
    }  else if(event->key() == Qt::Key_C) {
        ship->move(8);
    }  else if(event->key() == Qt::Key_Space) {
        //funkcja
    }  else if(event->key() == Qt::Key_T) {
        //funkcja
    }  else if (event->key() == Qt::Key_M) {
        //funkcja
    }
}
