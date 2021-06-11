#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "ship.h"
#include "shipblue.h"
#include "shipgreen.h"
#include "shipred.h"
#include "wynik.h"
#include <QTimer>
#include "wynik.h"


class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem* parent=0);
    ShipBlue* shipB;
    ShipGreen* shipG;
    ShipRed* shipR;
    QVector<Ship*> VecShip;
    void ustawGrafike();
    unsigned int kierunek;

private:
    unsigned int licznikWrogaStatkow;
    void dodajDoVecShip(Ship* statek);
    void moveShip();
    void czasstrzaly();
    QTimer* strzal;

    QTimer* czasKierunku;
    QTimer* czasRuchu;
    Wynik* WynEnemy;

private slots:
    void zmienKierunek();
    void wyslijMove();
    void wyslijstrzal();




};

#endif // ENEMY_H
