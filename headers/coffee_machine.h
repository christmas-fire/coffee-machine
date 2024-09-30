#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

// Объявление класса кофемолки
class CoffeeGrinder {
public:
    void grind(); // помол
};

// Объявление класса группы
class Group {
public:
    void boil(); // варкa
};

// Объявление класса бойлера
class Boiler {
public:
    void heat(); // нагрев
};

// Объявление класса форсунка
class SteamNozzle {
public:
    void steam(); // нагрев
    void mix(); // размешать
    void add(); // добавить
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
