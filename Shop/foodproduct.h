#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H
#include "product.h"
#include <QList>
#include <QString>
#include <QStringList>
#include<QDate>
class FoodProduct : public Product
{
public:
    //Constructor
    FoodProduct(QDate sbd,QString d,int sc,int n , double p);
    void sell(int n);
    QString toString();
    bool isExpired();

 private :
    QDate m_SellByDate;
    int DISCOUNT;
};

#endif // FOODPRODUCT_H
