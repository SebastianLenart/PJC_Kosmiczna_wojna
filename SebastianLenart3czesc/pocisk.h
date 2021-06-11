#ifndef POCISK_H
#define POCISK_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Pocisk: QObject, public QGraphicsPixmapItem
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
    QTimer* ruch;
    int predkosc;
    void usunPozaEkranem();
    void ustawKierunek(int kier, int PocWidth, int PocHeight);
    int kierunek;
    bool isDelete;

    int PocWidth;
    int PocHeight;
    QPointF PktCenter;
    int dx;
    bool IsEnemy;
    int obrazenia;

};

#endif // POCISK_H
