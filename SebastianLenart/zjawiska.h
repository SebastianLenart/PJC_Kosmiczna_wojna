#ifndef ZJAWISKA_H
#define ZJAWISKA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>

class Zjawiska: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Zjawiska(QGraphicsItem* parent =0);
    void setSizePix(double w, double h);
    virtual void ustawGrafike(QPixmap path);
    void setName(QString n);
    void setPointCenter(double a, double b);
    double getPixWidth();
    double getPixHeight();
    QPointF Center;
    virtual int  getPredkosc();
    QString name;


protected:
    double PixWidth;
    double PixHeight;

    unsigned int zmienPredkosc;

    //spowolnij, zabierz HP, unsignet int ??
};

#endif // ZJAWISKA_H
