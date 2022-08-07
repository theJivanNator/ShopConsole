#include "product.h"
#include "transaction.h"
#include <QList>
#include <QString>
#include <QStringList>
#include<QDate>
#include<string>
#include <sstream>
Product::Product(QString d, int sc, int n, double p)
{
	m_Desription = d;
	m_SupplierCode = sc;
	m_NoOfItems = n;
	m_PricePerItem = p;
	m_DateSupplied = QDate::currentDate();
}


void Product::sell(int n) {

    //Remove number of items and make a transaction
	m_NoOfItems = m_NoOfItems - n;

	m_Transactions.append(Transaction(n, m_PricePerItem, QDate::currentDate()));
}

int Product::getSupplierCode() {
	return m_SupplierCode;
}

void Product::setProuctCode(int pc) {

	m_ProductCode = pc;
}

int Product::getProductCode() {
	return m_ProductCode;
}

QString Product::toString() {
	QString trans;

	if (m_Transactions.size() < 1) {
		trans = "None";
	}
	else {
        //Get All Transactions
		foreach(Transaction t, m_Transactions) {
			trans.append(t.toString());
		}

	}
	return QString("\nDescription: %6 \nProduct Code : %1 \nNo.items: %2 \nPrice Per Item :R %3 \nDate Supplied : %4 \nSupplier Code: %5 \nTransactions: %7")
		.arg(m_ProductCode).arg(m_NoOfItems)
		.arg(m_PricePerItem)
		.arg(m_DateSupplied.toString())
		.arg(m_SupplierCode).arg(m_Desription).arg(trans)
		;

}

void Product::removeAll() {
	m_NoOfItems = 0;
	m_Desription = "";
	m_SupplierCode = 0;
	m_PricePerItem = 0;
	m_ProductCode = 0;
	m_DateSupplied = QDate::currentDate();
	m_Transactions.append(Transaction(0, 0, QDate::currentDate()));
}

bool Product::isExpired() {
	return false;
}

