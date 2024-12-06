#include <iostream>
#include "LandlinePhone.h"
#include "MobilePhone.h"

using namespace std;

const int MAX_PHONES = 100;

void displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Показать информацию о телефонах\n";
    cout << "2. Изменить свойства телефона\n";
    cout << "3. Вычислить минимальную цену\n";
    cout << "4. Добавить новый телефон\n";
    cout << "5. Удалить телефон\n";
    cout << "6. Выход\n";
}

int main() {
    Phone* phones[MAX_PHONES];
    int phoneCount = 0;

    // Создание 8 готовых объектов
    phones[phoneCount++] = new LandlinePhone("Panasonic", "KX-TG9321", 5000, "Домашний");
    phones[phoneCount++] = new MobilePhone("Samsung", "Galaxy S21", 70000, "Мобильный");
    phones[phoneCount++] = new LandlinePhone("Philips", "CD150", 3000, "Домашний");
    phones[phoneCount++] = new MobilePhone("Apple", "iPhone 13", 90000, "Мобильный");
    phones[phoneCount++] = new LandlinePhone("Siemens", "Gigaset C530", 4000, "Домашний");
    phones[phoneCount++] = new MobilePhone("Xiaomi", "Mi 11", 60000, "Мобильный");
    phones[phoneCount++] = new LandlinePhone("Motorola", "C1001", 2500, "Домашний");
    phones[phoneCount++] = new MobilePhone("Nokia", "3310", 3500, "Мобильный");

    int choice;
    while (true) {
        displayMenu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < phoneCount; ++i) {
                    cout << i + 1 << ". ";
                    phones[i]->displayInfo();
                }
                break;

            case 2: {
                int index;
                cout << "Введите номер телефона для изменения (1-" << phoneCount << "): ";
                cin >> index;
                if (index < 1 || index > phoneCount) {
                    cout << "Неверный номер!" << endl;
                    break;
                }
                --index; // Приведение к индексу массива

                string brand, model, color;
                double price;
                cout << "Введите новый бренд: ";
                cin >> brand;
                cout << "Введите новую модель: ";
                cin >> model;
                cout << "Введите новую цену: ";
                cin >> price;
                cout << "Введите новый тип: ";
                cin >> color;

                phones[index]->setBrand(brand);
                phones[index]->setModel(model);
                phones[index]->setPrice(price);
                phones[index]->setColor(color);
                break;
            }

            case 3: {
                for (int i = 0; i < phoneCount; ++i) {
                    cout << i + 1 << ". Минимальная цена: "
                         << phones[i]->calculateMinPrice() << endl;
                }
                break;
            }

            case 4: {
                if (phoneCount >= MAX_PHONES) {
                    cout << "Достигнуто максимальное количество телефонов!" << endl;
                    break;
                }
                string brand, model, color;
                double price;
                int type;
                cout << "Выберите тип телефона (1 - Стационарный, 2 - Мобильный): ";
                cin >> type;

                cout << "Введите бренд: ";
                cin >> brand;
                cout << "Введите модель: ";
                cin >> model;
                cout << "Введите цену: ";
                cin >> price;
                cout << "Введите тип: ";
                cin >> color;

                if (type == 1) {
                    phones[phoneCount++] = new LandlinePhone(brand, model, price, color);
                } else if (type == 2) {
                    phones[phoneCount++] = new MobilePhone(brand, model, price, color);
                } else {
                    cout << "Неверный тип!" << endl;
                }
                break;
            }

            case 5: {
                int index;
                cout << "Введите номер телефона для удаления (1-" << phoneCount << "): ";
                cin >> index;
                if (index < 1 || index > phoneCount) {
                    cout << "Неверный номер!" << endl;
                    break;
                }
                --index; // Приведение к индексу массива

                delete phones[index]; // Освобождение памяти
                for (int i = index; i < phoneCount - 1; ++i) {
                    phones[i] = phones[i + 1]; // Сдвиг элементов влево
                }
                --phoneCount; // Уменьшение количества телефонов
                break;
            }

            case 6:
                for (int i = 0; i < phoneCount; ++i) {
                    delete phones[i]; // Освобождение памяти перед выходом
                }
                return 0;

            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    }

    return 0;
}
