#ifndef POCISKKULA_H
#define POCISKKULA_H

#include "pocisk.h"


/**
 * @brief The PociskKula class
 * Klasa PociskKula i jej cechy indywidualne
 * \param PociskKula - konstruktor, w ktorym ustawia sie parametry tego obiektu
 * \param ustawGrafike - ustawienie grafiki obiektu
 * \param getPktKulaOgolny - zrwaca punkt przebywania kuli
 */


class PociskKula: public Pocisk
{
public:
    PociskKula(int kier=0, bool own = true);
    void ustawGrafike();
    QPointF getPktKulaOgolny();


};

#endif // POCISKKULA_H
