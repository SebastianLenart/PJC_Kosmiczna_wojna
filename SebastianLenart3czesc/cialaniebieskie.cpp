#include "cialaniebieskie.h"
#include "cialakrazace.h"
#include "planety.h"
#include "satelity.h"
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include <QObject>


CialaNiebieskie::CialaNiebieskie(QGraphicsScene* scenaGra, QGraphicsItem* parent) : scena(scenaGra), QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/image/SlonceV1.png"));
    this->setWHSlonca(166, 163);


    scena->addItem(this);
    this->setPos(x() + xS, y()+yS); // punkt slonca
    PunktSlonca = QPointF(this->pos().x()+Width/2, this->pos().y()+Height/2); // srodek slonca
    dodajPLaneteOrazSatelite(); //albo z poziomu game dodaj ta funckje

    this->getPksSrSlonca();
    this->getPksSrSloncaOgolny();

}



void CialaNiebieskie::dodajPLaneteOrazSatelite()
{
    Planety* Ziemia = new Planety(QString(":/image/image/ZiemiaV3.png"), 10); // wplyw metod wirtualnych
    Ziemia->setName(QString("Ziemia"));
    Ziemia->setSizeMap(104, 105); // to musi byc przedd setpozycja aby dzialalo!!!
    Ziemia->setPos(Ziemia->setDistance(250,this->getPksSrSloncaOgolny()));
    Ziemia->setPointShine(PunktSlonca.x(), PunktSlonca.y()); // centrum slonca
    scena->addItem(Ziemia);

    Satelity* SatelitaZiemi = new Satelity(QPixmap(":/image/image/SatelitaSztuczny.png"), 3, Ziemia);
    SatelitaZiemi->setSizeMap(112, 122);
    SatelitaZiemi->setName(QString("SatelitaGeo"));
    SatelitaZiemi->setPos(SatelitaZiemi->setDistance(110, Ziemia));
    scena->addItem(SatelitaZiemi);


    Satelity* KsiezycZiemi = new Satelity(QPixmap(":/image/image/ksiezyc.png"), 5, Ziemia);
    KsiezycZiemi->setSizeMap(109, 93);
    KsiezycZiemi->setName(QString("KsiezycZiemi"));
    KsiezycZiemi->setPos(KsiezycZiemi->setDistance(100, Ziemia, false));
    scena->addItem(KsiezycZiemi);

    mapaObKrazacych[Ziemia] = QVector<Satelity*> {SatelitaZiemi, KsiezycZiemi}; // dokoncz potem

    for(auto it=mapaObKrazacych.begin(); it!=mapaObKrazacych.end(); it++) {
//        for(auto itr=mapaObKrazacych.value())
//        qDebug()<<it.key()->nameCiala<<it.value(); // jak odczytac wektor???
    }



//    Planety* Mars = new Planety(QString(":/image/image/MarsV2.png"), 60); // wplyw metod wirtualnych
//    Mars->setName(QString("Mars"));
//    Mars->setSizeMap(301, 271);
//    Mars->setPos(Mars->setDistance(350,this->getPksSrSloncaOgolny()));
//    Mars->setPointShine(PunktSlonca.x(), PunktSlonca.y());
//    scena->addItem(Mars);

//    Satelity* KsiezycMarsa = new Satelity(QPixmap(":/image/image/ksiezyc.png"), 30, Mars);
//    KsiezycMarsa->setSizeMap(109, 93);
//    KsiezycMarsa->setName(QString("KsiezycMarsa"));
//    KsiezycMarsa->setPos(KsiezycMarsa->setDistance(100, Mars, false));
//    scena->addItem(KsiezycMarsa);

//    Planety* Jowisz = new Planety(QString(":/image/image/jowisz.png"), 40); // wplyw metod wirtualnych
//    Jowisz->setName(QString("Jowisz"));
//    Jowisz->setSizeMap(223, 223);
//    Jowisz->setPos(Jowisz->setDistance(600,this->getPksSrSloncaOgolny()));
//    Jowisz->setPointShine(PunktSlonca.x(), PunktSlonca.y());
//    scena->addItem(Jowisz);


}

QPointF CialaNiebieskie::getPksSrSlonca()
{
    return QPointF(Width/2,Height/2);
}

QPointF CialaNiebieskie::getPksSrSloncaOgolny()
{
    return QPointF(getPksSrSlonca()+this->pos());
}


void CialaNiebieskie::setWHSlonca(double w, double h)
{
    Width = w;
    Height = h;
}
