#ifndef CIALANIEBIESKIE_H
#define CIALANIEBIESKIE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "cialakrazace.h"
#include "planety.h"
#include "satelity.h"


/**
 * @brief The CialaNiebieskie class
 * Klasa odpowiedziala za tworzenie slonca oraz planet i satelit sterowanie ich parametrami
 * \param CialaNiebieskie - konstruktor odpowiedzialny za stworzenie slonca oraz wywolanie klasy
 * ktora tworzy planety i satelity
 * \param setWHSlonca - zapisuje do atrybutow dane wymiarowe slonca
 * \param dodajPLaneteOrazSatelite - tworzy planety i satelity i okresla ich parametry
 * \param getPksSrSlonca - zwraca punkt srodka slonca
 * \param getPksSrSloncaOgolny - zwraca punkt slonca na scenie
 */



class CialaNiebieskie:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CialaNiebieskie(QGraphicsScene* scenaGra, QGraphicsItem* parent =0); // slonce

    QGraphicsScene* scena;
    QList<QMap<Planety, Satelity>> ListaParCialKrazacych;



private:
    // metody
    void setWHSlonca(double w, double h);
    void dodajPLaneteOrazSatelite();
    QPointF getPksSrSlonca();
    QPointF getPksSrSloncaOgolny();

    // atrybuty
    double Width;
    double Height;
    double SrodekSlonca;
    double SrodekSloncaOgolny;

    QPointF PunktSlonca;
    int xS=100;
    int yS=100;
    QMap<Planety*, QVector<Satelity*>> mapaObKrazacych; // tylko do testow
};

#endif // CIALANIEBIESKIE_H
