#ifndef BOMBA_H
#define BOMBA_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bomba:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bomba(QString path, QGraphicsItem* parent =0);
    void ustawGrafike(QString path);
    void setSizePix(double w, double h);

private:
    double PixBombWidth;
    double PixBombHeight;
    QPointF centerBomby();
    QPointF centerBombyOgolny();

};

#endif // BOMBA_H
