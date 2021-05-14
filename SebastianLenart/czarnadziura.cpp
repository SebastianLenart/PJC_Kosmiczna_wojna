#include "czarnadziura.h"

CzarnaDziura::CzarnaDziura(QGraphicsItem *parent)
{
    ustawGrafike();

    //zrob okrag ew polygon
//    this->setOpacity(0.2);
}

void CzarnaDziura::ustawGrafike()
{
    this->setPixmap(QPixmap(":/image/image/CzarnaDziura.png"));
}

//zrobie moze klase do tego i wykrywanie kolizji po klasie!!!
//    QBrush bru(Qt::black);
//    QPen pen(Qt::black);
//    //    QGraphicsRectItem RecCzarna(BlackHole->pos().x(),BlackHole->pos().y(),BlackHole->getPixWidth(),BlackHole->getPixHeight());
//    QRectF RecCzarna(BlackHole->pos().x(),BlackHole->pos().y(),BlackHole->getPixWidth()+60,BlackHole->getPixHeight()+60);
//    QGraphicsEllipseItem* okrag;
//    //    painter.drawEllipse(RecCzarna);
//    okrag = scenaGra->addEllipse(RecCzarna, pen, bru);
//    okrag->setOpacity(0.8);
//    //    okrag->hide(); // ukrywa
//    okrag->stackBefore(BlackHole); // przesloniecie
//    //    okrag->setPos(mapToScene(10,10));
