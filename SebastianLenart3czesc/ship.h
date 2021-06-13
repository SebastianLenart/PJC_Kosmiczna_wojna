#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include "pocisk.h"
#include "pociskkula.h"
#include "pocisklaser.h"
#include "pociskpodwojny.h"
#include "bomba.h"
#include <QGraphicsScene>

/**
 * @brief The Ship class
 * Klasa odpowiedzialna za realizacie wszystkich funkcjonalnosci statka kosmicznego
 *
 * \param Ship - w konstruktorze uruchomiany jest timer ktory sprawdza co jakis czas zycie statka
 * \param move - metoda odpowiedzialna na poruszanie sie w odpowiednim kierunku statku
 * \param zmienBron - metoda dzieki ktorej gracz moze zmieniac aktualna bron
 * \param setusunStatek - metoda zapisujaca ze dany statek jest juz zniszczony
 * \param getusunStatek - metoda zwracajaca informacje ze dany statek jest zniszczony
 * \param strzal - metoda na podstawie argumentow pozwala na wystrzelenie danej broni z danego miejsca
 * \param getBron - zwraca aktualna bron
 * \param setPointCenterObiekt - zapisuje srodkowy punkt grafiki/obiektu
 * \param getPktSrodek - zwraca srodkowy punkt grafiki/obiektu
 * \param getPktShipOgolny - wirtualna metoda zwracajaca pozycje obiektu klasy pochodnej
 * \param getCzestStrzalow - zwraca czestotliwosc strzalow boota
 * \param setActive - zapisywanie statku jako aktywnego w grze, glownie chodzi o czekajace nieaktywne statki wroga
 * \param getActive - zwraca informacje czy dany stetek jest aktywny w grze
 * \param setSpeed - zapisywanie predkosci do statku, glownie w celach testowych
 * \param getSpeed - pobieranie predkosci statku
 * \param getHP - zwracanie ilosci zycia HP
 * \param getStrBron - zwraca aktualna bron slownie
 * \param teleport - po wywolaniu tej metody statek zmienia pozycje wedlug umiejscowienia teleportow
 * \param checkLifeShip - monitorowanie co jakis czas czy dany statek nie zostal zniszczony oraz wystawianie odpowiednich informacji czy to nastapilo
 * \param kolizje - metoda ktora wykrywa czy statek nie dotknal elementu innej klasy podczas poruszania sie i ewentualne dalsze reakcje np. spowolnienie
 * \param aktualizacja - monitorowanie czy w statek nie trafil zaden pocisk i ewentualne dalsze odejmowanie zycia
 */


class Ship:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ship(QGraphicsItem* parent =0);

    // metody
    void move(int kierunek);
    void zmienBron();
    void setusunStatek(bool a = false);
    bool getusunStatek();
    void strzal(int wyborbroni, QPointF pozycja);
    int getBron();
    void setPointCenterObiekt(double a, double b);
    QPointF getPktSrodek();
    virtual QPointF getPktShipOgolny();
    int getCzestStrzalow();
    void setActive(bool a);
    bool getActive();
    void setSpeed(int s);
    int getSpeed();
    double getHP();
    QString getStrBron();
    void teleport();

    // atrybuty
    QPointF PktCenter;
    int iloscBroni;
    Pocisk* bullet;
    Bomba* bomba;
    bool IsEnemy;
    QVector<Pocisk*> VecPoc;
    int wyborBroni;

public slots:
     void checkLifeShip();

protected:

     //metody
     void czeststrzalow(int a);
     /*virtual*/ void kolizje();
     void aktualizacja();

     // atrybuy
    int ShipWidth = 62;
    int ShipHeight = 108;
    QPointF centerPkt = QPointF(31,54);
    QPointF centerPktOgolny;
    int speed = 5;
    int Orginalspeed;
    double HP;
    int Paliwo;
    bool IsDelete;
    int obecnyKierunek;
    int CzestotliwoscStrzalowBoota;
    bool active;

};

#endif // SHIP_H
