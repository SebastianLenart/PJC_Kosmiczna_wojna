#include "enemy.h"
#include "ship.h"
#include "shipblue.h"
#include "shipgreen.h"
#include "shipred.h"
#include <QTimer>
#include <stdlib.h> // rand()
#include <time.h> // rand()
#include <QDebug>
#include <game.h>

extern Game* game;

Enemy::Enemy(QGraphicsItem *parent)
{
    this->setPixmap(QPixmap(":/image/image/StacjaWroga.png"));
    this->setPos(700, -20);
    licznikWrogaStatkow = 0;

    shipB = new ShipBlue();
    shipB->setPos(700, 0);
    dodajDoVecShip(shipB);

    shipG = new ShipGreen();
    shipG->setPos(763,0);
    dodajDoVecShip(shipG);

    shipR = new ShipRed();
    shipR->setPos(827,0);
    dodajDoVecShip(shipR);

    // ruch pojazdów:
    // potrzebne sa 2 timery niestety:
    // 1 ustawia kierunk co pare sekund a 2 wysyła sane co pare ms

    moveShip();
}

void Enemy::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/StacjaWroga.png"));
}

void Enemy::dodajDoVecShip(Ship *statek)
{
    statek->setRotation(180);
    VecShip.append(statek);
}

void Enemy::moveShip()
{
    czasKierunku = new QTimer();
    connect(czasKierunku, SIGNAL(timeout()), this ,SLOT(zmienKierunek()));
    czasKierunku->start(3500);

    czasRuchu = new QTimer();
    connect(czasRuchu, SIGNAL(timeout()), this ,SLOT(wyslijMove()));
    czasRuchu->start(20);
}

void Enemy::zmienKierunek()
{
    kierunek = rand()%4; // moze zwiekszyc od % 9 ale zobacze jeszcze

}

void Enemy::wyslijMove()
{
    shipB->move(kierunek);
}
