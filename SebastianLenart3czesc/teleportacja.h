#ifndef TELEPORTACJA_H
#define TELEPORTACJA_H

#include "zjawiska.h"


/**
 * @brief The Teleportacja class
 *
 * \param ustawGrafike - ustawienie grafiki obiektu
 * \param setPozDrugiego - ustawienie pozycji drugiego konca teleportacji
 * \param getPozDrugiego - zwracanie punktu drugiego konca teleportacji
 */


class Teleportacja:public Zjawiska {
    Q_OBJECT

public:
    Teleportacja(QString name, bool b = true, QGraphicsItem* parent=0);
    void ustawGrafike(bool f=true);

    void setPozDrugiego(QPointF p);
    QPointF getPozDrugiego();
private:
    QPointF pozDrugiego;
};

#endif // TELEPORTACJA_H
