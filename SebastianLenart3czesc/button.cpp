#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>

Button::Button(QString name, QColor color, QGraphicsItem* parent) : QObject(), QGraphicsRectItem(parent)
{
    // wymiary
    setRect(0,0, 200, 50);
    ButWidth = 200;
    ButHeight = 50;
    QBrush brush;
    brush.setStyle(Qt::SolidPattern); // SolidPattern
    brush.setColor(color);
    setBrush(brush);

    // tekst
    tekst = new QGraphicsTextItem(name, this);
    int xPos = this->rect().width()/2 - tekst->boundingRect().width()/2;
    int yPos = this->rect().height()/2 - tekst->boundingRect().height()/2;
    tekst->setPos(xPos, yPos);

    // pozwolenie na hover
    setAcceptHoverEvents(true);
}

int Button::GetButWidth()
{
    return ButWidth;
}

int Button::GetButHeight()
{
    return ButHeight;
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // zmiana koloru
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkYellow);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // zmiana koloru
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}
