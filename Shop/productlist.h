#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H
#include "product.h"


class ProductList {
  public:
    //Add product
    int add(Product* p);
    void sell(int pc,int n);
    void remove(int pc);
    void delelteAll();

private:
   bool codeUsed(int pc);
    QList<Product*> m_Product_List;
};

#endif // PRODUCTLIST_H
