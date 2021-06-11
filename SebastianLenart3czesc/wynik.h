#ifndef WYNIK_H
#define WYNIK_H

#include <QGraphicsTextItem>
#include <QGraphicsRectItem>

class Wynik: public QGraphicsTextItem
{
public:
    Wynik(QGraphicsItem* parent = 0);
    void setWynik(QString wynikk);
    void daneWroga(int iloscW, double HPW, QString bronW);
    void danePlayera(double HPP, QString bronP);

};

#endif // WYNIK_H
