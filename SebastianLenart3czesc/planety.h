#ifndef PLANETY_H
#define PLANETY_H

#include "cialakrazace.h"
#include <QPixmap>
#include <QList>
#include <QPointF>


/**
 * @brief The Planety class
 * Klasa tworzy orbitujece planety
 *
 * \param UstawGrafike - metoda ktora ustawia grafike obiektu
 * \param getPktPlanetyOgolny - metoda ktora zwraca pkt obiektu na glownej scenie
 * \param setDistance -  metoda, ktora na podstawie podanego jako argument obiektu i odleglosci zapisuje i zwraca punkt oddalony o te podane dane
 * \param setTimer - metoda ktora ustawia timer obrotu
 * \param rotacja - metoda ktora w pierwszej rotacji zapisuje pkt do vektora a w nastepnych rotacjach posluguje sie tymi zapisanymi punktami, aby mozna bylo
 * dodaj funkcjonalnosc rotacji wokol wlasnej osi
 */




class Planety: public CialaKrazace
{
    Q_OBJECT
public:
    Planety(QGraphicsItem* parent =0);
    Planety(QString path, unsigned int czasOsi, QGraphicsItem* parent =0);

    // metody
    void setTimer(unsigned int czas, bool flaga=true);
    void UstawGrafike(QPixmap path);
    QPointF getPktPlanetyOgolny();
    QPointF setDistance(double d, QPointF point);

    // atrybuty
    QList<QPointF> okrag;
    unsigned int TimerWokolSlonca;
private:
    unsigned int TimerOsi;
    QPointF centrum;
    bool flaga;
    unsigned int i;
    QPointF srodekPlanety;
    unsigned int kier;


private slots:
    void rotacja();

};

#endif // PLANETY_H
