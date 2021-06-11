#ifndef PLAYER_H
#define PLAYER_H

#include "ship.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include "ship.h"
#include "wynik.h"

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(int w=1, QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event);
    Ship* ship; // niech zostanie
    Wynik* wynPlayera;
};

#endif // PLAYER_H
