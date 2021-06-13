#ifndef MENU_H
#define MENU_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <button.h>
#include <QGraphicsScene>


/**
 * @brief The Menu class
 *
 * \param Menu - konstuktor w ktorym tworzone sa przyciski do menu
 */


class Menu: public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    // konstruktor
    Menu(int width, int height, QGraphicsItem* parent = 0);


    // atrybuty
    Button* Play;
    Button* Ustawienia;
    Button* Quit;
    QList <Button*> ListaPrzyciskow;

private:
    int MenuWidth;
    int MenuHeight;

};

#endif // MENU_H
