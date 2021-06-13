#ifndef TUNEL_H
#define TUNEL_H

#include "zjawiska.h"


/**
 * @brief The Tunel class
 *  * Klasa glownie sluzy do tego aby latwo mozna bylo wykryc kolizje na podstawie przyrownania danego obiektu do odpowiedniej klasy
 * \param ustawGrafike - metoda ktora ustawia grafike obiektu
 */

class Tunel:public Zjawiska
{
    Q_OBJECT
public:
    Tunel(QGraphicsItem* parent=0);
    void ustawGrafike();
};

#endif // TUNEL_H
