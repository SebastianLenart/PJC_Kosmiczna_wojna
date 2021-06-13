#ifndef POCISKPODWOJNY_H
#define POCISKPODWOJNY_H

#include "pocisk.h"

/**
 * @brief The PociskPodwojny class
 * Klasa PociskPodwojny i jej cechy indywidualne
 * \param PociskPodwojny - konstruktor, w ktorym ustawia sie parametry tego obiektu
 * \param ustawGrafike - ustawienie grafiki obiektu
 * \param getPktKulaOgolny - zrwaca punkt przebywania kuli
 * \param ustawPoz - metoda ktora ustawia w odpowiednich miejscach pociski na statku zaleznie od kierunku poruszania sie
 */


class PociskPodwojny: public Pocisk
{
public:
    PociskPodwojny(int kier, QPointF poz, int odl, bool own = true);
    void ustawGrafike();
    QPointF getPktPodwOgolny();

private:
    void ustawPoz(int kierun, QPointF pozyc , int odle);
};

#endif // POCISKPODWOJNY_H
