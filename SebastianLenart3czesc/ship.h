#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pociskpodwojny.h"
#include "bomba.h"
#include <QGraphicsScene>

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
    void strzal(int wyborbroni, QPointF pozycja);
    int getBron();
    int iloscBroni;
    Pocisk* bullet;
    Bomba* bomba;
    void setPointCenterObiekt(double a, double b);
    QPointF PktCenter;
    QPointF getPktSrodek();
    virtual QPointF getPktShipOgolny();
    int getCzestStrzalow();
    void setActive(bool a);
    bool getActive();
    void setSpeed(int s);
    int getSpeed();
    double getHP();
    QString getStrBron();

public slots:
     void checkLifeShip();

protected:
    int ShipWidth = 62;
    int ShipHeight = 108;
    QPointF centerPkt = QPointF(31,54);
    QPointF centerPktOgolny; // zrob funkcje do tego
    int speed = 5;
    int Orginalspeed;

    double HP;
    int Paliwo;
    bool IsDelete;
    int obecnyKierunek;
    void czeststrzalow(int a);
    int CzestotliwoscStrzalowBoota;
    /*virtual*/ void kolizje();
    void aktualizacja();
    bool active;



};

#endif // SHIP_H
