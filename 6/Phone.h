#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <string>

using namespace std;

class Phone {
protected:
    string brand;
    string model;
    double price;
    string color;

public:
    Phone(const string& b, const string& m, double p, const string& c)
        : brand(b), model(m), price(p), color(c) {}

    virtual ~Phone() {}

    void setBrand(const string& b) { brand = b; }
    void setModel(const string& m) { model = m; }
    void setPrice(double p) { price = p; }
    void setColor(const string& c) { color = c; }

    virtual double calculateMinPrice() const = 0; // Чисто виртуальная функция

    void displayInfo() const {
        cout << "Бренд: " << brand << ", Модель: " << model 
             << ", Цена: " << price << ", Тип: " << color << endl;
    }
};

#endif // PHONE_H

