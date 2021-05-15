#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pocisknaprowadzajacy.h"

class Ship:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ship(QGraphicsItem* parent =0);
    void move(int kierunek);
    bool IsEnemy;
    QVector<Pocisk*> VecPoc;
    int wyborBroni;
    void zmienBron();
    void setusunStatek(bool a = false);
    bool getusunStatek();
    void strzal(int wyborbroni);
    int getBron();

public slots:
     void checkLifeShip();



protected:
    int ShipWidth = 62;
    int ShipHeight = 108;
    QPointF centerPkt = QPointF(31,54);
    QPointF centerPktOgolny; // zrob funkcje do tego
    int speed = 5;

    int HP;
    int Paliwo;
    bool IsDelete;
    int obecnyKierunek;



};

#endif // SHIP_H
