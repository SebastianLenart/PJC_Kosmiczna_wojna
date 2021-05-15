#include "planety.h"
#include "satelity.h"
#include "cialakrazace.h"
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include "cialaniebieskie.h"
#include "game.h"
#include <QLineF>
#include <QPointF>


Planety::Planety(QGraphicsItem *parent)
{

}

Planety::Planety(QString path, unsigned int czasOsi, QGraphicsItem *parent)
{
    i=0;
    flaga = true;
    kier=1;
    UstawGrafike(path);
    setTimer(czasOsi);
}

void Planety::UstawGrafike(QPixmap path)
{
    this->setPixmap(path);
}

QPointF Planety::getPktPlanetyOgolny() // zrob jako publiczny slot!!!
{
    return getPktSrodek()+this->pos();
}

QPointF Planety::setDistance(double d, QPointF point)
{
    QLineF dystans (QPointF(point.x() + d, point.y()), point);
    return QPointF(dystans.p1()-getPktSrodek());
}



void Planety::rotacja()
{
    if(i>=360) { i=0; flaga = false; }
    if(!flaga) {
        this->setTransformOriginPoint(PlWidht/2, PlHeight/2);// polowa pixmapy ZiemiaV3 w pixelach
        this->setRotation(kier*i*10);
        this->setPos(QPointF(okrag.at(i).x()-PlWidht/2,okrag.at(i).y()-PlHeight/2)); // nei wolno this->Plheight.. bo dziedziczymy zmienna PLHeight..
//        qDebug()<<mapToScene(PlWidht/2,PlHeight/2)<<"ss"<<QPoint(PlWidht/2+this->pos().x(),PlHeight/2+this->pos().y());
    } else {// ponizej pos() sie nie zmienia mimo ze obiekt sie rusza ??? :( skopiowac 51 do 57 linikji????
        this->setTransformOriginPoint(QPointF(PktSlonca.x()-this->x(),PktSlonca.y()-this->y()));// srodek slonca
        this->setRotation(kier*i);
        okrag.append(QPointF(mapToScene(PlWidht/2,PlHeight/2)));
//        qDebug()<<getPktPlanetyOgolny();
//        qDebug()<<mapToScene(PlWidht/2,PlHeight/2)<<"ss"<<QPoint(PlWidht/2+this->pos().x(),PlHeight/2+this->pos().y()); -->> TO SAMO
        //powyzej mapToScene jerst bardziej dokladnie!!!
    }
    i++;
}


void Planety::setTimer(unsigned int czas, bool flaga)
{
    if(flaga) {
        TimerOsi = czas;
        QTimer* rotations = new QTimer(this);

        connect(rotations, SIGNAL(timeout()), this, SLOT(rotacja()));
        rotations->start(TimerOsi);
    }
}
