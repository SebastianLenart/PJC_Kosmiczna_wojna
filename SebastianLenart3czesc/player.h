#ifndef PLAYER_H
#define PLAYER_H

#include "ship.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include "ship.h"
#include "wynik.h"


/**
 * @brief The Player class
 * Klasa odpowiedzialna za stworzenie statku gracza oraz za sterowanie tym statkiem
 *
 * \param Player - konstruktor odpowiedzialny za stworzenie odpowiedniego statku oraz wyswietlanie danych tego obiektu
 * \param keyPressEvent - metoda odpowiedzialna za sterowanie statkiem
 */



class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(int w=1, QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event);

    Ship* ship;
    Wynik* wynPlayera;
};

#endif // PLAYER_H
