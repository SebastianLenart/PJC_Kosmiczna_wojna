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
#include "enemy.h"
#include "wynik.h"


/**
 * @brief The Game class
 * Klasa ktora zarzadza cala gra oraz ktora tworzy mape
 *
 * \param displayMenu - metoda ktora tworzy i wyswietla elementy menu
 * \param gameover - metoda ktora unieruchania gre i wyswietla zwyciezce
 * \param start - metoda ktora tworzy scene gracza, wrogow
 * \param ZaladujMape - metoda ktorza wysyla odpowiednie dane do metody ktora bezposrednio tworzy mape
 * \param stworzZjawiska - metoda ktora na podstawie otrzymanych danych tworzy konkretny obiekty na scenie
 */




class Game: public QGraphicsView//, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Game(QWidget* parent=NULL);

    // metody
    void displayMenu();
    void gameover(QString text);

    // public attributes
    QGraphicsScene* scenaGra;
    QGraphicsScene* scenaMenu;
    QGraphicsView* viewGra;
    Menu* menu;
    CialaNiebieskie* PlanetySatelity;
    Zjawiska* DalekieObiekty;    
    QGraphicsScene* overScena;
    QGraphicsView* overView;

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

    Player* player;
    Enemy* enemy;

};

#endif // GAME_H
