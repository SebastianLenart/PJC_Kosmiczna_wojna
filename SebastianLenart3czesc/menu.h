#ifndef MENU_H
#define MENU_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <button.h>
#include <QGraphicsScene>

class Menu: public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    // konstruktor
    Menu(int width, int height, QGraphicsItem* parent = 0);

    // publiczne metody

    // publiczne atrybuty
    Button* Play;
    Button* Ustawienia;
    Button* Quit;
    QList <Button*> ListaPrzyciskow;

private:
    int MenuWidth;
    int MenuHeight;

};

#endif // MENU_H
