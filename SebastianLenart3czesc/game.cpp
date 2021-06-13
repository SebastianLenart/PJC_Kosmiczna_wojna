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
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QFont>
#include <wynik.h>


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

    connect(menu->ListaPrzyciskow[1], SIGNAL(clicked()), this,SLOT(close())); // Quit
    //    connect(menu->ListaPrzyciskow[2], SIGNAL(clicked()), this,SLOT(close())); // Ustawienia
    connect(menu->ListaPrzyciskow[0], SIGNAL(clicked()), this,SLOT(start())); // Play
}

void Game::gameover(QString text)
{
//    scenaGra->clear(); // powoduje to blad, nie wiem czemu

    for(int i = 0, n = scenaGra->items().size(); i < n; i++) {
        scenaGra->items()[i]->setEnabled(false);
    }


    Wynik* wyn = new Wynik();
    wyn->setWynik(text);
    int xPos = scenaGra->width()/2 - wyn->boundingRect().width()/2 - 100;
    int yPos = scenaGra->height()/2 - wyn->boundingRect().height()/2;
    wyn->setPos(xPos, yPos);
    scenaGra->addItem(wyn);
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

    player = new Player(1);
    //    player->PlayerShip->setPos(800, 700);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus(); // reakcja na przyciski
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

    stworzZjawiska(1000,450, 3,5,1); // Mglawica
    stworzZjawiska(1115,80, 4,2,2); // Tunel
    stworzZjawiska(100,870, 1,1,3); // Czarna dziura
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
                BlackHole->setPos(x+i*108, y+j*108);
                BlackHole->setSizePix(108, 108); // pixeli
                scenaGra->addItem(BlackHole);
                break;
            case 4:
                telePom = new Teleportacja(QString("Pomarancz"+QString::number(j)), false);
                telePom->setPos(x+j*(-803), y+j*423);
                telePom->setSizePix(126, 126);
                //scenaGra->addItem(telePom);
                if(j==1) {
                    telePom->setPozDrugiego(QPointF(x+0*(-803), y+0*423));
                } else telePom->setPozDrugiego(QPointF(x+1*(-803), y+1*423));
                VecTelepor.push_front(telePom);
                break;
            case 5:
                teleFiol = new Teleportacja(QString("Fiolet"+QString::number(j)));
                teleFiol->setPos(x+j*623, y+j*423);
                teleFiol->setSizePix(126, 126);
                //scenaGra->addItem(teleFiol);
                if(j==1) {
                    teleFiol->setPozDrugiego(QPointF(x+0*(623), y+0*423));
                } else teleFiol->setPozDrugiego(QPointF(x+1*(623), y+1*423));
                VecTelepor.append(teleFiol);
                break;
            case 6: ;
                Bum = new Bomba();
                Bum->setPos(x+j*623, y+j*423);
                //Bum->setSizePix(84, 80);
                Bum->i = 1000; // zeby bomba nie zniknela za  szybko
                scenaGra->addItem(Bum);
                break;
            }
        }
    }
}















