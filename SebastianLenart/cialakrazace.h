#ifndef CIALAKRAZACE_H
#define CIALAKRAZACE_H

#include <QGraphicsPixmapItem>
#include <QObject>
//#include "planety.h"
//#include "satelity.h" // nie dziala tutaj, nwm czemu

//class Planety;
//class Satelity;

class CialaKrazace: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CialaKrazace(QGraphicsItem* parent=0);
    void setName(QString nazwa);
    void setPointShine(int a, int b);
    void setPointCenterObiekt(double a, double b);
    double getWidth();
    double getHeight();
    QPointF getPktSrodek();
    QPointF getPktSrodekSatelity();
    virtual QPointF setDistance(double d,QGraphicsItem* obiekt);

    QPointF PktSlonca;
    QPointF PktCenter;
    QPointF PktSatelity;
    QString nameCiala;
    virtual void UstawGrafike(QString path); // jezeli przyrownam do zera to blad
    void setSizeMap(double w, double h);



//    int PlWidht;
//    int PlHeight;
protected:

    QLineF distance; // czy double???
    /*virtual*/ double distanceTo(QGraphicsItem* item);

    double PlWidht;
    double PlHeight;
    double Distance;


};

#endif // CIALAKRAZACE_H
