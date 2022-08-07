#include "transaction.h"

Transaction::Transaction(int n, double p, QDate td)
{
	m_NoOfItems = n;
	m_PricePerItem = p;
	m_TransactionDate = td;
}
QString Transaction::toString() {
	return QString("\nNumber of Items : %1 \nPricePerItem: %2 \nTransaction Date : %3 ")
		.arg(m_NoOfItems)
		.arg(m_PricePerItem)
		.arg(m_TransactionDate.toString())

		;
}
