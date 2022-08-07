#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QList>
#include<QDate>
#include "transaction.h"

class Product
{

public:   
    //Constructor
    Product(QString d, int sc ,int n ,double p);
    //Sell Product
    void sell(int n);
    int getSupplierCode();
    void setProuctCode(int pc);
    int getProductCode();
    QString toString();
    void removeAll();
    bool isExpired();

    protected :
    QString m_Desription;
    int m_SupplierCode;
    int m_NoOfItems;
    QDate m_DateSupplied;
    double m_PricePerItem;
    int m_ProductCode;
    QList<Transaction> m_Transactions;
};



#endif // PRODUCT_H
