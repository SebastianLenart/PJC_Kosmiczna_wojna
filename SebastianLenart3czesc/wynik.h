#ifndef WYNIK_H
#define WYNIK_H

#include <QGraphicsTextItem>
#include <QGraphicsRectItem>


/**
 * @brief The Wynik class
 * \param setWynik - wyswietlanie wyniku rozgrywki
 * \param daneWroga - wyswietlanie informacji o wrogu
 * \param danePlayera - wyswietlanie informacji o graczu
 * \param odliczanieBomby - wyswietlanie czasu do wybuchu bomby
 */


class Wynik: public QGraphicsTextItem
{
public:
    Wynik(QGraphicsItem* parent = 0);
    void setWynik(QString wynikk);
    void daneWroga(int iloscW, double HPW, QString bronW);
    void danePlayera(double HPP, QString bronP);
    void odliczanieBomby(int i);

};

#endif // WYNIK_H
