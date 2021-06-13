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
#include "wynik.h"

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
    czasstrzaly();

    WynEnemy = new Wynik();
    WynEnemy->daneWroga(VecShip.size(),VecShip[0]->getHP(), VecShip[0]->getStrBron());
    WynEnemy->setPos(900, -20);
    game->scenaGra->addItem(WynEnemy);
    flagapetla=false;
}

void Enemy::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/StacjaWroga.png"));
}

void Enemy::dodajDoVecShip(Ship *statek) // polimorfizm ???
{
    statek->setRotation(180);
    statek->setActive(false);
    VecShip.append(statek);
}

void Enemy::moveShip()
{
    VecShip[0]->setActive(true);

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
    // usuwanie statku
    if(VecShip[0]->getusunStatek()) {
        game->scenaGra->removeItem(VecShip[0]);
        VecShip.pop_front(); // usun z poczatku listy
        if(VecShip.size()==0)
        {
            strzal->stop();
            czasKierunku->stop();
            czasRuchu->stop();
            game->gameover(QString("Wygrana"));

        } else {
            VecShip[0]->setusunStatek(false); // nasteopny statek jeszcze nie jest usuniety, zbedne
            VecShip[0]->setActive(true);
            strzal->stop();
            czasstrzaly();
            WynEnemy->daneWroga(VecShip.size(),VecShip[0]->getHP(), VecShip[0]->getStrBron());
        }
    }


    QList<QGraphicsItem*> items = collidingItems();
    for(int i=0; i<items.size(); i++) {
        if(typeid(*items[i]) == typeid(Bomba)) {
            bom = dynamic_cast<Bomba*>(items[i]);
            flagapetla = true;
        }
    }

    if(flagapetla)
    {
        if(bom->wybuch) {
            for(int i=0; i<VecShip.size(); i++) {
                game->scenaGra->removeItem(VecShip[i]);
            }

            game->scenaGra->removeItem(this);
            VecShip.erase(VecShip.begin(),VecShip.end()); // usuwanie
            strzal->stop();
            czasKierunku->stop();
            czasRuchu->stop();
            game->gameover(QString("Wygrana"));

        }
    }


    if(VecShip.size()!=0)
    {
        VecShip[0]->move(kierunek);
        WynEnemy->daneWroga(VecShip.size(),VecShip[0]->getHP(), VecShip[0]->getStrBron());
    }
}

void Enemy::czasstrzaly()
{
    strzal = new QTimer();
    connect(strzal,SIGNAL(timeout()), this, SLOT(wyslijstrzal()));
    strzal->start(VecShip[0]->getCzestStrzalow());
}


void Enemy::wyslijstrzal()
{
    VecShip[0]->strzal(VecShip[0]->getBron(), VecShip[0]->getPktShipOgolny()); // 2 argument to pkt pozycji
}
