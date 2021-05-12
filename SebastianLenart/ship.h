#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>

class Ship:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ship(QGraphicsItem* parent =0);
    void move(int kierunek);

protected:
    int ShipWidth = 62;
    int ShipHeight = 108;
    QPointF centerPkt = QPointF(31,54);
    QPointF centerPktOgolny; // zrob funkcje do tego
    int speed = 5;

};

#endif // SHIP_H
