#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QList>
#include <QString>
#include <QStringList>
#include<QDate>
class Transaction
{
public:
   //Constructor
    Transaction(int n , double p , QDate td);
    QString toString();

private:
    int m_NoOfItems;
    double m_PricePerItem;
    QDate m_TransactionDate;
};


#endif // TRANSACTION_H
