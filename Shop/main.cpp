#include <QCoreApplication>
#include "product.h"
#include <QList>
#include <QString>
#include <QStringList>
#include<QDate>
#include<iostream>
#include "foodproduct.h"
#include "productlist.h"
using namespace  std;
int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	//Make objects
	Product* pSoap = new Product("Soap 30g", 15, 100, 7.50);
	Product* pCream = new Product("Face Cream 500g", 15, 70, 20);
	Product* pToothPaste = new Product("Tooth Paste 15ml", 5, 150, 11);
	FoodProduct* pApples = new FoodProduct(QDate::currentDate(), "Fresh Apples", 11, 50, 6.99);
	Product* pPens = new Product("Bic Pens Pack", 30, 100, 7);
	ProductList pl;

	//Store Objects
	pl.add(pSoap);
	pl.add(pCream);
	pl.add(pToothPaste);
	pl.add(pApples);
	pl.add(pPens);

	//Information before sales
	cout << pSoap->toString().toStdString() << endl;
	cout << pCream->toString().toStdString() << endl;
	cout << pToothPaste->toString().toStdString() << endl;
	cout << pApples->toString().toStdString() << endl;
	cout << pPens->toString().toStdString() << endl;

	//Sales
	cout << "\n--------Sales-------------" << endl;
	cout << "\n_____Sale of Soap_____ :5" << endl;
	pSoap->sell(5);
	cout << pSoap->toString().toStdString() << endl;

	cout << "\n____Sale of Face Cream_____ :2" << endl;
	pCream->sell(2);
	cout << pCream->toString().toStdString() << endl;
	if (pCream->isExpired()) {
		cout << "The Face Cream is Expired :" << endl;

	}
	else {
		cout << "The Face Cream is Not Expired" << endl;
	}

	cout << "\n_____Sale of Tooth Paste_____ :1" << endl;
	pToothPaste->sell(1);
	cout << pToothPaste->toString().toStdString() << endl;

	cout << "\n_____Sale of Apples_____ :20" << endl;
	pApples->sell(20);
	cout << pApples->toString().toStdString() << endl;
	if (pApples->isExpired()) {
		cout << "The Apples Are Expired :" << endl;
	}
	else {
		cout << "The Apples Are Not Expired" << endl;
	}

	cout << "\n____Sale of Pens_____ :5" << endl;
	pPens->sell(5);
	cout << pPens->toString().toStdString() << endl;

	//remove items
	pl.delelteAll();

	return a.exec();
}
