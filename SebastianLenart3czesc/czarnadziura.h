#ifndef CZARNADZIURA_H
#define CZARNADZIURA_H

#include "zjawiska.h"


/**
 * @brief The CzarnaDziura class
 * Klasa glownie sluzy do tego aby latwo mozna bylo wykryc kolizje na podstawie przyrownania danego obiektu do odpowiedniej klasy
 * \param ustawGrafike - ustawia grafike obiektu
 */


class CzarnaDziura: public Zjawiska
{
    Q_OBJECT
public:
    CzarnaDziura(QGraphicsItem* parent=0);
    void ustawGrafike();
};

#endif // CZARNADZIURA_H
