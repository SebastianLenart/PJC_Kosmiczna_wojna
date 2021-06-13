#include "menu.h"
#include "button.h"
#include <QDebug>
#include <QGraphicsScene>
#include <game.h>

Menu::Menu(int width, int height,QGraphicsItem* parent) : MenuWidth(width), MenuHeight(height)
{
    setPixmap(QPixmap(":/image/image/Menu.png"));

    Play = new Button(QString("Play"));
    int xBut = MenuWidth/2 - Play->GetButWidth()/2;
    int yPlay = 70; // MenuHeight/2 - Play->GetButHeight()/2;
    Play->setPos(xBut, yPlay);
    ListaPrzyciskow.append(Play);

    Ustawienia = new Button(QString("Ustawienia"));
    int yUstawienia = 70 + Ustawienia->GetButHeight()+30;
    Ustawienia->setPos(xBut, yUstawienia);
    //ListaPrzyciskow.append(Ustawienia);

    Quit = new Button(QString("Quit"));
    int yQuit = 70 + 2*Ustawienia->GetButHeight()+2*30;
    Quit->setPos(xBut, yQuit);
    ListaPrzyciskow.append(Quit);

}

