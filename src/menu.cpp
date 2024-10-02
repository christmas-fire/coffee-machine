#include "menu.h"
#include "recipes.h"

int Menu::numberName() {
    int input;
    std::cout << "Введите номер напитка: "; 
    std::cin >> input;
    return input;
}

std::string Menu::searchName(std::vector<Recipe>& r, int &input) {
    return r[input - 1].getName();
}

void Print::printMap(std::map<std::string, unsigned> ingredients) {
    for(auto ingredient : ingredients) {
        std::cout << ingredient.first << " " << ingredient.second << ", ";
    }
    std::cout << std::endl;
}

void Print::printVector(std::vector<Recipe> r) {
    for (size_t i = 0; i < r.size(); i++) {
        std::cout << i + 1 << ". " << r[i].getName() << std::endl;
    }
}

void Menu::start(std::vector<Recipe> r, CoffeeMachine& cm) {
    while (true) {

        std::cout << "+--------------+" << std::endl;
        for (size_t i = 0; i < r.size(); i++) {
            std::cout << "| " << i + 1 << ". " << r[i].getName() << std::endl;
        };
        std::cout << "+--------------+" << std::endl;

        std::cout << "Выберете напиток: ";
        int input;
        std::cin >> input;

        if(input < 1 && input > r.size()){
            break;
        } 
        std::string name = searchName(r, input);
        std::cout << "+------------------------+" << std::endl;
        std::cout << "| Вы выбрали: "<< name << std::endl;
        std::cout << "| Время изготовления: " << cm.prepareCoffee(r[input - 1]) << std::endl;
        std::cout << "+------------------------+" << std::endl;

        std::string off;
        std::cout << "Продолжить?\n";
        std::cin >> off;
        
        if(off == "0") {
            std::cout << "Машина выключена";
            break;
        } else if(off == "1") {
            continue;
        } else {
            std::cout << "ban";
            break;
        }
        //Zapusk coffee_machine
        //Конвертируем рецепт в обекты
        //запускаем функции оброботки обектов(заварка)
    }
}