#include "game.h"
#include "menu.h"
#include "cialaniebieskie.h"
#include "zjawiska.h"
#include "mglawica.h"
#include "tunel.h"
#include "teleportacja.h"
#include "bomba.h"
#include "player.h"
#include "ship.h"
#include "shipblue.h"
#include "shipgreen.h"
#include "shipred.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QRectF>
#include <QPainter>


Game::Game(QWidget* parent)
{
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::displayMenu()
{
    // ScenaMenu
    scenaMenu = new QGraphicsScene();
    scenaMenu->setSceneRect(0,0,600, 343);
    setFixedSize(600,343);
    setScene(scenaMenu);

    menu = new Menu(scenaMenu->width(), scenaMenu->height());
    scenaMenu->addItem(menu);
    for(int i=0; i<menu->ListaPrzyciskow.size(); i++) {
        scenaMenu->addItem(menu->ListaPrzyciskow[i]);
    }

    connect(menu->ListaPrzyciskow[2], SIGNAL(clicked()), this,SLOT(close())); // Quit
    //    connect(menu->ListaPrzyciskow[2], SIGNAL(clicked()), this,SLOT(close())); // Ustawienia
    connect(menu->ListaPrzyciskow[0], SIGNAL(clicked()), this,SLOT(start())); // Play
}


void Game::start()
{
    //    delete scenaMenu; !!! z tym nie dzialaja grafiki Planet !!!!!

    setFixedSize(1500,1000);

    // ScenaGra
    scenaGra = new QGraphicsScene();
    viewGra = new QGraphicsView(scenaGra);
    scenaGra->setSceneRect(0,0,1700, 950);
    scenaGra->setBackgroundBrush(QBrush(QImage(":/image/image/Tapeta_1.png")));
    setScene(scenaGra);

    // planety i satelity
    ZaladujMape();


    //zrob moze klase do tego i wykrywanie kolizji po klasie!!!
    //    QBrush bru(Qt::black);
    //    QPen pen(Qt::black);
    //    //    QGraphicsRectItem RecCzarna(BlackHole->pos().x(),BlackHole->pos().y(),BlackHole->getPixWidth(),BlackHole->getPixHeight());
    //    QRectF RecCzarna(BlackHole->pos().x(),BlackHole->pos().y(),BlackHole->getPixWidth()+60,BlackHole->getPixHeight()+60);
    //    QGraphicsEllipseItem* okrag;
    //    //    painter.drawEllipse(RecCzarna);
    //    okrag = scenaGra->addEllipse(RecCzarna, pen, bru);
    //    okrag->setOpacity(0.8);
    //    //    okrag->hide(); // ukrywa
    //    okrag->stackBefore(BlackHole); // przesloniecie
    //    //    okrag->setPos(mapToScene(10,10));




    player = new Player(1);
    //    player->PlayerShip->setPos(800, 700);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scenaGra->addItem(player);
    scenaGra->addItem(player->ship);


    enemy = new Enemy();
    scenaGra->addItem(enemy);
    for(auto i=0; i<enemy->VecShip.size(); i++) {
        scenaGra->addItem(enemy->VecShip[i]);
        enemy->VecShip[i]->stackBefore(enemy);
    }
    //    player->ship->stackBefore(enemy); // odwrotnie
    enemy->stackBefore(player->ship);


}

void Game::ZaladujMape()
{
    PlanetySatelity = new CialaNiebieskie(scenaGra);
    //powyzsze jeszcze dopracuje, jest jeszcze wiele do zrobienia, ale ogolnie 6/10 jest

    stworzZjawiska(1000,450, 3,5,1); // Mglawica
    stworzZjawiska(1115,80, 4,2,2); // Tunel
    stworzZjawiska(100,470, 1,1,3); // Czarna dziura
    stworzZjawiska(1150,300, 1,2,4); // telepom
    stworzZjawiska(60,300, 1,2,5); // telefiol
    stworzZjawiska(1400,-20, 1,1,6); // bomba


    unsigned int i = 0;
    for(auto j = VecTelepor.begin(); j<VecTelepor.end(); j+=2) {
        mapaTelepor[VecTelepor.at(i++)] = VecTelepor.at(i++);
        //        qDebug()<<(*j)->name; // dziala
    }

    for(auto it=mapaTelepor.begin(); it!=mapaTelepor.end(); it++) {
        //        qDebug()<<it.key()->name<<it.value()->name;
        scenaGra->addItem(it.key());
        scenaGra->addItem(it.value());
    }

    //funkcja przelatujaca kometa daje nowe bonusy ???


}

void Game::stworzZjawiska(int x, int y, int wiersze, int kolumny, int a)
{
    bool flaga=true;
    for( auto i=0; i<wiersze; i++) {
        for(auto j = 0; j<kolumny; j++) {

            switch(a) {
            case 1:
                Mgl = new Mglawica(flaga);
                Mgl->setPos(x+i*84, y+j*84);
                scenaGra->addItem(Mgl);
                flaga=!flaga;
                VecMgl.append(Mgl);
                break;
            case 2:
                Wormhole = new Tunel();
                Wormhole->setPos(x+i*95, y+j*95);
                scenaGra->addItem(Wormhole);
                VecTunel.append(Wormhole);
                break;
            case 3:
                BlackHole = new CzarnaDziura();
                BlackHole->setPos(x+i*423, y+j*423);
                BlackHole->setSizePix(423, 423);
                scenaGra->addItem(BlackHole);
                break;
            case 4:
                telePom = new Teleportacja(QString("Pomarancz"+QString::number(j)), false);
                telePom->setPos(x+j*(-803), y+j*423);
                telePom->setSizePix(126, 126);
                //scenaGra->addItem(telePom);
                VecTelepor.push_front(telePom);
                break;
            case 5:
                teleFiol = new Teleportacja(QString("Fiolet"+QString::number(j)));
                teleFiol->setPos(x+j*623, y+j*423);
                teleFiol->setSizePix(126, 126);
                //scenaGra->addItem(teleFiol);
                VecTelepor.append(teleFiol);
                break;
            case 6:
                Bum = new Bomba(QString(":/image/image/bomba.png"));
                Bum->setPos(x+j*623, y+j*423);
                //                Bum->setSizePix(84, 80);
                scenaGra->addItem(Bum);
                break;
            }
        }
    }
}





























