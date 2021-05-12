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


Player::Player(QGraphicsItem* parent)
{
    ship = new Ship();
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W) {
        //funkcja
    } else if(event->key() == Qt::Key_A) {
        //funkcja
    }
    else if(event->key() == Qt::Key_D) {
        //funkcja
    }  else if(event->key() == Qt::Key_S) {
        //funkcja
    }  else if(event->key() == Qt::Key_Q) {
        //funkcja
    }  else if(event->key() == Qt::Key_E) {
        //funkcja
    }  else if(event->key() == Qt::Key_Z) {
        //funkcja
    }  else if(event->key() == Qt::Key_C) {
        //funkcja
    }  else if(event->key() == Qt::Key_Space) {
        //funkcja
    }  else if(event->key() == Qt::Key_T) {
        //funkcja
    }  else if (event->key() == Qt::Key_M) {
        //funkcja
    }
}
