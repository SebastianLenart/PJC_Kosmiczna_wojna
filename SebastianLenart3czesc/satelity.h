#ifndef SATELITY_H
#define SATELITY_H

#include <cialakrazace.h>
#include <planety.h>

/**
 * @brief The Satelity class
 * Klasa tworzy orbitujece Satelity
 * \param UstawGrafike - metoda ktora ustawia grafike obiektu
 * \param getPktPlanetyOgolny - metoda ktora zwraca pkt obiektu na glownej scenie
 * \param setDistance -  metoda, ktora na podstawie podanego jako argument obiektu i odleglosci zapisuje i zwraca punkt oddalony o te podane dane
 * \param setOwner - ustawia wlasciciela danej satlity wokol ktorej sie obraca
 * \param rotacja - metoda ktora cyklicznie ustawia pozycje od wlasciciela czyli od planety
 */



class Satelity: public CialaKrazace
{
    Q_OBJECT
public:
    Satelity(QGraphicsItem* parent=0);
    Satelity(QPixmap path, unsigned int czasOsi, Planety* Ow, QGraphicsItem* parent=0);
    void UstawGrafike(QPixmap path);
    QPointF getPktSatelityOgolny();
    QPointF setDistance(double d, Planety *obiekt, bool pozycja=true);
    void setOwner(Planety* Ow);


private:
    void setTimer(unsigned int czas);

    int i=0;
    bool flag=0;
    Planety* Owner;
    QPointF* wksOkragPlanety;
    unsigned int TimerRot;
    double dystans;
    bool pozSat;

private slots:
    void rotacja();

};

#endif // SATELITY_H
