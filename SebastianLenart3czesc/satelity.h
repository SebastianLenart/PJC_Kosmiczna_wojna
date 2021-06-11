#ifndef SATELITY_H
#define SATELITY_H

#include <cialakrazace.h>
#include <planety.h>

class Satelity: public CialaKrazace
{
    Q_OBJECT
public:
    Satelity(QGraphicsItem* parent=0);
    Satelity(QPixmap path, unsigned int czasOsi, Planety* Ow, QGraphicsItem* parent=0);
    void UstawGrafike(QPixmap path);
    QPointF getPktSatelityOgolny();
    QPointF setDistance(double d, Planety *obiekt, bool pozycja=true);
    void setOwner(Planety* Ow);


private:

    int i=0;
    bool flag=0;
    Planety* Owner;
    QPointF* wksOkragPlanety;
    void setTimer(unsigned int czas);
    unsigned int TimerRot;
    double dystans;
    bool pozSat;
private slots:
    void rotacja();

};

#endif // SATELITY_H
