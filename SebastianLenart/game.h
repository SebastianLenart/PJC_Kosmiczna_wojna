#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "menu.h"
#include "cialaniebieskie.h"
#include "zjawiska.h"
#include "mglawica.h"
#include "czarnadziura.h"
#include "tunel.h"
#include "teleportacja.h"
#include "bomba.h"
#include "player.h"
#include "ship.h"


class Game: public QGraphicsView//, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    // contructors
    Game(QWidget* parent=NULL);

    // public methods
    void displayMenu();

    // public attributes
    QGraphicsScene* scenaGra;
    QGraphicsScene* scenaMenu;
    QGraphicsView* viewGra;
    Menu* menu;
    CialaNiebieskie* PlanetySatelity;
    Zjawiska* DalekieObiekty;

public slots:
    void start();
private:
    void ZaladujMape();
    void stworzZjawiska(int x, int y, int wiersze, int kolumny, int a);
    Mglawica* Mgl;
    Tunel* Wormhole;
    Teleportacja* telePom;
    Bomba* Bum;
    QVector<Teleportacja*> VecTelepor;
    QMap<Teleportacja*, Teleportacja*> mapaTelepor;
    Teleportacja* teleFiol;
    CzarnaDziura* BlackHole;
    QVector<Mglawica*> VecMgl;
    QVector<Tunel*> VecTunel;

    QRectF rectangle;
    QPainter painter;
    //vektor mglawic oraz wormholi

    Player* player;
};

#endif // GAME_H
