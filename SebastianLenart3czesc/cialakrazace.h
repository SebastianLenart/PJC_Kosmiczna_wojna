#ifndef CIALAKRAZACE_H
#define CIALAKRAZACE_H

#include <QGraphicsPixmapItem>
#include <QObject>


/**
 * @brief The CialaKrazace class
 * Klasa podstawowa zawierajaca wspolne cechy klas Planety oraz Satelity
 *
 * \param setName - metoda zapisujaca nazwe obiektu do atrybutu
 * \param setPointShine - zapisuje do atrybutu pozycje slonca
 * \param setPointCenterObiekt - na podstawie argumentow oblicza srodek grafiki
 * \param getWidth - zwraca szerosc
 * \param getHeight - zwraca wysokosc
 * \param getPktSrodek - zwraca obliczony wczesniej punkt srodka grafiki
 * \param setDistance - wirtualna metoda, ktora na podstawie podanego jako argument obiektu i odleglosci zapisuje punkt oddalony o te podane dane
 * \param UstawGrafike - wirtualna metoda, ktorsa ustawia grafiki w klasach nizej
 * \param setSizeMap - na podstawie argumentow zapisuje dane wymiarowe i oblicza srodek grefiki
 *
 */


class CialaKrazace: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CialaKrazace(QGraphicsItem* parent=0);

    // metody
    void setName(QString nazwa);
    void setPointShine(int a, int b);
    void setPointCenterObiekt(double a, double b);
    double getWidth();
    double getHeight();
    QPointF getPktSrodek();
    virtual QPointF setDistance(double d,QGraphicsItem* obiekt);
    virtual void UstawGrafike(QString path); // jezeli przyrownam do zera to blad
    void setSizeMap(double w, double h);

    // atrybuty
    QPointF PktSlonca;
    QPointF PktCenter;
    QPointF PktSatelity;
    QString nameCiala;


protected:

    QLineF distance;
    double PlWidht;
    double PlHeight;
    double Distance;

};

#endif // CIALAKRAZACE_H
