#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

#include "ingredients.h"

// Объявление класса кофемолки
class CoffeeGrinder {
public:
    void grind(CoffeeBeans& c); // помол
};

// Объявление класса группы
class Group {
public:
    void boil(CoffeeBeans& c); // варкa
};

// Объявление класса бойлера
class Boiler {
public:
    void heat(Water& w); // нагрев
};

// Объявление класса форсунка
class SteamNozzle {
public:
    void steam(WetIngredient& ingredient); // нагрев
    void mix(DryIngredient& ingredient); // размешать
    void add(Ingredient& ingredient); // добавить
};

// Объявление класса кофемашины целиком
class CoffeeMachine {
private:
    CoffeeGrinder grinder;
    Boiler boiler;
    SteamNozzle nozzle;
public:
    void prepareCoffee(); // приготовить кофе
};

#endif  // COFFEE_MACHINE_H
