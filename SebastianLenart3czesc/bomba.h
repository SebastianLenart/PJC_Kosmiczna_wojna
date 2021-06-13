#ifndef BOMBA_H
#define BOMBA_H

#include "pocisk.h"
#include <QTimer>
#include "wynik.h"
//#include "game.h"


/**
 * @brief The Bomba class
 * Klasa odpowiedzialna za wystrzal bomby, odliczanie czasu i jej znikniecie
 *
 * \param Bomba - ustawienie niezbednych atrybutow m.in. do kogo nalezy bomba
 * \param ustawGrafike - ustawienie grafiki obiektu
 * \param getPktBombaOgolny - zwraca punkt xy obiektu na scenie
 * \param setTouch - ustawia noTouch w celu aby statek nie mogl wystrzelonej bomby znowu zgarnac, poniewaz pierwsza bombe
 * statek musi zdobyc przez jej dotkniecie, nastepne juz nie
 * \param getTouch - zrwaca bool czy bomba moze kogos zniszczyc czy ktos moze ja przywlaszczyc
 * \param setPozycje - ustawia atrybut pozycje, odpowiedzialny za umiejscowienie odliczanie na bombie
 * \param getPozycje - zwraca punkt pozycji ustawiony przedtem
 * \param startOdliczania - ustawia timer odliczania oraz pokazuje cyfry na bombie
 * \param move - slot odpowiedzialny za ruch - bomba stoi w miejscu
 * \param odlF - slot odpowiedzialny za zmiejszenie cyfer na bombie i pozniejsze usuwanie obiektu
 */





class Bomba: public Pocisk
{
    Q_OBJECT
public:
    Bomba(bool own = true);

    // metody
    void ustawGrafike();
    QPointF getPktBombaOgolny();
    void setTouch(bool a);
    bool getTouch();
    void setPozycje(QPointF pkt);
    QPointF getPozycje();
    void startOdliczania();

    // atrybuty
    bool wybuch;
    Wynik* odlW;
    int i;

public slots:
   void move();
   void odlF();

private:
   bool noTouch;
    QTimer* odliczT;
    QPointF pozycja;

};

#endif // BOMBA_H
