#include <QApplication>
#include "game.h"



/**
 *   \mainpage
 *   \par Kosmiczna wojna
 *   \author Sebastian Lenart
 *   \date 13.06.2021
 *   \version final_V2
 *   /par
 **/







Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    game->displayMenu();
//    game->start();


    return a.exec();
}
