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



/**
 * @brief The Enemy class
 * Klasa odpowiedzialna za tworzenie statkow wroga
 *
 * \param ustawGrafike - metoda ustawia grafike obiektu
 * \param dodajDoVecShip - metoda dodaje stworzone obiekty, czyli statki
 * \param moveShip - metoda ustawia timery ktore zmieniaja kierunek i wysylaja go do klasy ship
 * \param czasstrzaly - metoda ktora uruchamia timer co ile ma maja sie strzaly wysylac
 * \param zmienKierunek - metoda losuje kierunek poruszania sie statku co jakis czas
 * \param wyslijMove - metoda oprocz wysylania danych do klasy ship, pilnuje czy statek nie zostal zniszczony
 * oraz czy bomba nie zostala podlozona w teren wroga
 * \param wyslijstrzal - metoda ktora wysyla do klasy ship jaki pocisk ma byc wystrzelony i z jakiego miejsca
 */




class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem* parent=0);\

    // metody
    void ustawGrafike();

    // atrybuty
    ShipBlue* shipB;
    ShipGreen* shipG;
    ShipRed* shipR;
    QVector<Ship*> VecShip;
    unsigned int kierunek;

private:

    void dodajDoVecShip(Ship* statek);
    void moveShip();
    void czasstrzaly();

    QTimer* strzal;
    unsigned int licznikWrogaStatkow;
    QTimer* czasKierunku;
    QTimer* czasRuchu;
    Wynik* WynEnemy;
    Bomba* bom;
    bool flagapetla;

private slots:
    void zmienKierunek();
    void wyslijMove();
    void wyslijstrzal();

};

#endif // ENEMY_H
