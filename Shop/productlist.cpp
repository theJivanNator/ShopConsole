#include "productlist.h"
#include "product.h"
#include <QList>
#include <QString>
#include<QDate>
#include<sstream>
#include "product.h"

int ProductList::add(Product* p) {
	int countSupp = 0;
	if (codeUsed(p->getSupplierCode() * 1000)) {

		for (int i = 0; i < m_Product_List.size(); ++i) {
			if (m_Product_List.at(i)->getSupplierCode() == p->getSupplierCode()) {
				countSupp++;

			}
		}

		int code = p->getSupplierCode() * 1000;
		p->setProuctCode(code + countSupp);
		m_Product_List.append(p);
		return code;
	}
	else {
		int code = p->getSupplierCode() * 1000;
		p->setProuctCode(code + countSupp);
		m_Product_List.append(p);
		return code;
	}

}
void ProductList::sell(int pc, int n) {

	for (int i = 0; i < n; ++i) {
		if (m_Product_List.at(i)->getProductCode() == pc) {
			m_Product_List.at(i)->sell(pc);
		}
	}

}
void ProductList::remove(int pc) {
	for (int i = 0; i < m_Product_List.size(); ++i) {
		if (m_Product_List.at(i)->getProductCode() == pc) {

			m_Product_List.at(i)->removeAll();
		}
	}
}
void ProductList::delelteAll() {
	for (int i = 0; i < m_Product_List.size(); ++i) {
		m_Product_List.at(i)->removeAll();
	}
	m_Product_List.clear();
}
bool ProductList::codeUsed(int pc) {
	bool isFound;
	for (int i = 0; i < m_Product_List.size(); ++i) {
		if (m_Product_List.at(i)->getProductCode() == pc) {
			isFound = true;
			break;
		}
	}
	if (isFound) {
		return true;
	}
	else {
		return false;
	}
}
