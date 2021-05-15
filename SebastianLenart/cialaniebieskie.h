#ifndef CIALANIEBIESKIE_H
#define CIALANIEBIESKIE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "cialakrazace.h"
#include "planety.h"
#include "satelity.h"

class CialaNiebieskie:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CialaNiebieskie(QGraphicsScene* scenaGra, QGraphicsItem* parent =0); // slonce

    QGraphicsScene* scena;
    QList<QMap<Planety, Satelity>> ListaParCialKrazacych;


public slots:


private:
    double Width;
    double Height;
    double SrodekSlonca;
    double SrodekSloncaOgolny;
    void setWHSlonca(double w, double h);
    QPointF PunktSlonca;
    int xS=100;
    int yS=100;
    void dodajPLaneteOrazSatelite();
    QPointF getPksSrSlonca();
    QPointF getPksSrSloncaOgolny();
    QMap<Planety*, QVector<Satelity*>> mapaObKrazacych;
};

#endif // CIALANIEBIESKIE_H
