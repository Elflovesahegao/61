#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"

class MobilePhone : public Phone {
public:
    MobilePhone(const string& b, const string& m, double p, const string& c)
        : Phone(b, m, p, c) {}

    double calculateMinPrice() const override {
        return price * 0.85; // Пример: минимальная цена на 15% ниже
    }

    void displayInfo() const {
        Phone::displayInfo(); // Вызов метода базового класса
        cout << "Тип: Мобильный телефон" << endl;
    }
};

#endif // MOBILEPHONE_H


