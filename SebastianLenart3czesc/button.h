#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>


/**
 * @brief The Button class
 * Klasa odpowiedzialna za wyglad i reakcje przyciskow
 * \param Button - konstruktor odpowiedzialny za kosmetyke przycisku i jego napis
 * \param GetButWidth - metoda zwraca szerokosc przycisku
 * \param GetButHeight - metoda zwraca wysokosc przycisku
 * \param mousePressEvent - metoda odpowiedzialna za wywolanie reakcji
 * \param hoverEnterEvent - zmiana kosmetyki przycisku po najechaniu kursorem
 */


class Button: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Button(QString name, QColor color= Qt::blue, QGraphicsItem* parent = NULL);

    // metody
    int GetButWidth();
    int GetButHeight();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

signals:
    void clicked();

private:

    // atrybuty
    QGraphicsTextItem* tekst;
    int ButWidth;
    int ButHeight;
};

#endif // BUTTON_H
