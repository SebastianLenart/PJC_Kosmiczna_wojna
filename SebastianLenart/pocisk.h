#ifndef POCISK_H
#define POCISK_H

#include <QGraphicsRectItem>
#include <QObject>

class Pocisk: QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pocisk(QGraphicsItem* parent =0);
    virtual void ustawGrafike();
};

#endif // POCISK_H
