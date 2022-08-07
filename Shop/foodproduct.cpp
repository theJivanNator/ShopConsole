#include "foodproduct.h"
#include <QList>
#include <QString>
#include <QStringList>
#include<QDate>
#include<sstream>
FoodProduct::FoodProduct(QDate sbd, QString d, int sc, int n, double p) :Product(d, sc, n, p)
{
	m_SellByDate = sbd;
}
void FoodProduct::sell(int n) {

	m_NoOfItems = m_NoOfItems - n;

	m_Transactions.append(Transaction(n, m_PricePerItem, QDate::currentDate()));
}
QString FoodProduct::toString() {
	QString trans;
	if (m_Transactions.size() < 1) {
		trans = "None";
	}
	else
	{
		foreach(Transaction t, m_Transactions) {
			trans.append(t.toString());
		}
	}
	return QString("\nDescription: %7 \nProduct Code : %1 \nNo.items: %2 \nPrice Per Item :R %3 \nDate Supplied : %4 \nSupplier Code: %5 \nSel by Date : %6 \nTransactions:%8")
		.arg(m_ProductCode).arg(m_NoOfItems)
		.arg(m_PricePerItem)
		.arg(m_DateSupplied.toString())
		.arg(m_SupplierCode)
		.arg(m_SellByDate.toString())
		.arg(m_Desription).arg(trans);
}

bool FoodProduct::isExpired() {
	if (m_SellByDate <= QDate().currentDate())
	{
		return false;
	}
	else
	{
		return true;
	}

}
