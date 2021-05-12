#ifndef PLANETY_H
#define PLANETY_H

#include "cialakrazace.h"
#include <QPixmap>
#include <QList>
#include <QPointF>

class Planety: public CialaKrazace
{
    Q_OBJECT
public:
    Planety(QGraphicsItem* parent =0);
    Planety(QString path, unsigned int czasOsi, QGraphicsItem* parent =0);

    void setTimer(unsigned int czas, bool flaga=true);

    void UstawGrafike(QPixmap path);
    unsigned int TimerWokolSlonca;
    QPointF getPktPlanetyOgolny();
    QPointF setDistance(double d, QPointF point);
    QList<QPointF> okrag;
private:
    unsigned int TimerOsi;
    QPointF centrum;
//    int PlWidht;
//    int PlHeight;
    bool flaga;
    unsigned int i;

    QPointF srodekPlanety;
    unsigned int kier; // zrob publiczne set i get


private slots:
    void rotacja();


};

#endif // PLANETY_H
