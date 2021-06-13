#ifndef MGLAWICA_H
#define MGLAWICA_H

#include "zjawiska.h"


/**
 * @brief The Mglawica class
 * Klasa glownie sluzy do tego aby latwo mozna bylo wykryc kolizje na podstawie przyrownania danego obiektu do odpowiedniej klasy
 * \param ustawGrafike - metoda ktora ustawia grafike obiektu
 */



class Mglawica: public Zjawiska
{
    Q_OBJECT
public:
    Mglawica(bool b=true, QGraphicsItem* parent=0);
    void ustawGrafike(bool f);
};

#endif // MGLAWICA_H
