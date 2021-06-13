#ifndef POCISK_H
#define POCISK_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>


/**
 * @brief The Pocisk class
 * Klasa podstawowa zawierajaca wspolne cechy pociskow
 *
 * \param Pocisk - konstruktor uruchamia timer ktory co jakis czas uruchamia metode move
 * \param ustawGrafike - wirtualna metoda, ktorsa ustawia grafiki w klasach nizej
 * \param setPointCenterObiekt - zapisuje punkt srodka grafiki/obiektu
 * \param getPktSrodek - zwraca punkt srodka grafiki/obiektu
 * \param getPktShipOgolny - zwraca punkt obiektu/grafiki na mapie
 * \param getIsEnemy - zwraca informacje czy pocisk nalezy do wroga
 * \param getObrazenia - zwraca ilosc obrazen danej broni
 */


class Pocisk: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pocisk(QGraphicsItem* parent =0);

    virtual void ustawGrafike();
    void setPointCenterObiekt(double a, double b);
    QPointF getPktSrodek();
    virtual QPointF getPktShipOgolny();
    bool getIsEnemy();
    int getObrazenia();

public slots:
    virtual void move();

protected:

    void usunPozaEkranem();
    void ustawKierunek(int kier, int PocWidth, int PocHeight);

    int kierunek;
    bool isDelete;
    QTimer* ruch;
    int predkosc;
    int PocWidth;
    int PocHeight;
    QPointF PktCenter;
    int dx;
    bool IsEnemy;
    int obrazenia;
};

#endif // POCISK_H
