#include "pocisk.h"
#include "game.h"
#include "QDebug"


extern Game* game;

Pocisk::Pocisk(QGraphicsItem* parent)
{
    ruch = new QTimer();
    connect(ruch, SIGNAL(timeout()), this, SLOT(move()));
    ruch->start(5); // potem zmienna prekosc
    isDelete = false;
    usunPozaEkranem();
}



void Pocisk::ustawGrafike() { }

void Pocisk::move() {
    if(isDelete) return;

    switch(kierunek) {

    case 0:
        setPos(x(), y()-dx);
        break;
    case 1:
        setPos(x()-dx, y());
        break;
    case 2:
        setPos(x()+dx, y());
        break;
    case 3:
        setPos(x(), y()+dx);
        break;
    case 4:
        setPos(x()-dx, y()-dx);
        break;
    case 5:
        setPos(x()+dx, y()-dx);
        break;
    case 6:
        setPos(x()-dx, y()+dx);
        break;
    case 7:
        setPos(x()+dx, y()+dx);
        break;
    default:
        game->scenaGra->removeItem(this); // usuwa pierwsza kule ktora sie nie usuwa
        delete this;
        ruch->stop();
        break;
    }

    usunPozaEkranem();
}


void Pocisk::usunPozaEkranem()
{
    if(pos().x()<0 || pos().x()>game->scenaGra->width() || pos().y()<0 || pos().y()>game->scenaGra->height()) {
        game->scenaGra->removeItem(this); // ?? zadziala???
        delete this;
        ruch->stop(); // wyeliminowalo spowolnienie ruchu, super!
    }
    //    qDebug() << game->scenaGra->width()<<game->scenaGra->height(); // 1700 i 950
}

void Pocisk::ustawKierunek(int kier, int PocWidth, int PocHeight)
{
    setTransformOriginPoint(PocWidth/2, PocHeight/2);
    switch(kier) {
    case 0:
        setRotation(0);
        break;
    case 1:
        setRotation(270);
        break;
    case 2:
        setRotation(90);
        break;
    case 3:
        setRotation(180);
        break;
    case 4:
        setRotation(315);
        break;
    case 5:
        setRotation(45);
        break;
    case 6:
        setRotation(225);
        break;
    case 7:
        setRotation(135);
        break;
    }
}

void Pocisk::setPointCenterObiekt(double a, double b)
{
    PktCenter = QPointF(a/2, b/2);
}

QPointF Pocisk::getPktSrodek()
{
    return PktCenter;
}

QPointF Pocisk::getPktShipOgolny() { }

bool Pocisk::getIsEnemy()
{
    return IsEnemy;
}

int Pocisk::getObrazenia()
{
    return obrazenia;
}


