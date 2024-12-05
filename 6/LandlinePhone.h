#ifndef LANDLINEPHONE_H
#define LANDLINEPHONE_H

#include "Phone.h"

class LandlinePhone : public Phone {
public:
    LandlinePhone(const string& b, const string& m, double p, const string& c)
        : Phone(b, m, p, c) {}

    double calculateMinPrice() const override {
        return price * 0.9; // Пример: минимальная цена на 10% ниже
    }

    void displayInfo() const {
        Phone::displayInfo(); // Вызов метода базового класса
        cout << "Тип: Стационарный телефон" << endl;
    }
};

#endif // LANDLINEPHONE_H

