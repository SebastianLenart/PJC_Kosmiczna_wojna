#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    // konstruktor
    Button(QString name, QColor color= Qt::blue, QGraphicsItem* parent = NULL);

    // publiczne metody
    int GetButWidth();
    int GetButHeight();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

signals:
    void clicked();

private:

    // prywatne atrybuty
    QGraphicsTextItem* tekst;
    int ButWidth;
    int ButHeight;
};

#endif // BUTTON_H
