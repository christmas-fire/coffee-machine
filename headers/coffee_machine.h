#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

#include "ingredients.h"
#include "recipes.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Recipe;

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
    void add(Ingredient& ingredient, int amount); // добавить
};



// Объявление класса кофемашины целиком
class CoffeeMachine {
private:
    CoffeeGrinder grinder;
    Group group;
    Boiler boiler;
    SteamNozzle nozzle;
public:
    int prepareCoffee(Recipe& r); // приготовить кофе
};

#endif  // COFFEE_MACHINE_H
