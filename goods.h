#ifndef GOODS_H
#define GOODS_H

#include <iostream>
using namespace std;

class Goods {
public:
    Goods() {};
    Goods(string name, int price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    ~Goods() {
        cout << "Goods object " << name << " is being destroyed." << endl;
    }

    string name = "";
    int price = 0;
    int quantity = 0;

    void printGoodsData() {
        cout << setw(12) << name << setw(7) << price 
             << setw(10) << quantity << endl;
    }
};

#endif // GOODS_H