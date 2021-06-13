#ifndef ZJAWISKA_H
#define ZJAWISKA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>


/**
 * @brief The Zjawiska class
 * \param setSizeMap - na podstawie argumentow zapisuje dane wymiarowe i oblicza srodek grefiki
 * \param UstawGrafike - wirtualna metoda, ktorsa ustawia grafiki w klasach nizej
 * \param setName - metoda zapisujaca nazwe obiektu do atrybutu
 * \param setPointCenter - na podstawie argumentow oblicza srodek grafiki
 * \param getPixWidth - zwraca szerosc
 * \param getPixHeight - zwraca wysokosc
 */


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

    QString name;


protected:
    double PixWidth;
    double PixHeight;
    unsigned int zmienPredkosc;

};

#endif // ZJAWISKA_H
