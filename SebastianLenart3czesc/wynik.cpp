#include "wynik.h"
#include <QFont>
#include <QGraphicsRectItem>

Wynik::Wynik(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
//    setPlainText(QString("Test"));
    setDefaultTextColor((Qt::white));
    setFont(QFont("times", 50));

}

void Wynik::setWynik(QString wynikk)
{
    setPlainText(QString(wynikk));
}

void Wynik::daneWroga(int iloscW, double HPW, QString bronW)
{
    setPlainText(QString("Ilosc wrogow: ")+QString::number(iloscW) + QString("\n")+
                 QString("HP: ")+QString::number(HPW)+QString("\n")+
                 QString("Aktualna bron: ")+QString(bronW));
    setFont(QFont("times", 15));
}

void Wynik::danePlayera(double HPP, QString bronP)
{
                 setPlainText(QString("HP: ")+QString::number(HPP)+QString("\n")+
                 QString("Aktualna bron: ")+QString(bronP));
                 setFont(QFont("times", 15));
}

void Wynik::odliczanieBomby(int i)
{
    setPlainText(QString::number(i));
    setFont(QFont("times", 40));
}
