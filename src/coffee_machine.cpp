#include "coffee_machine.h"
#include "ingredients.h"
#include "cstdio"

void CoffeeGrinder::grind(CoffeeBeans& c) {
    printf("Кофе поступил на помол! Время: %d Статус: %d\n", c.getTime(), c.getStatus());
    c.setTime(c.getTime()+15);
    c.setStatus(true);
    printf("Кофе закончил молоться! Время: %d Статус: %d\n", c.getTime(), c.getStatus());
}

void Group::boil(CoffeeBeans& c) {
    if (c.getStatus()) {
        c.setTime(c.getTime()+20);
        printf("Кофе сварился! Время: %d\n", c.getTime());
    } else {
        printf("Кофе не молотый! Ошибка!");
    }
}

void Boiler::heat(Water& w) {
    printf("Вода поступила в бойлер! Температура: %d Время: %d\n", w.getTemperature(), w.getTime());
    int toAdd = 100 - w.getTemperature();
    w.setTemperature(w.getTemperature()+toAdd);
    w.setTime(w.getTime()+toAdd);
    printf("Вода закипела! Температура: %d Время: %d\n", w.getTemperature(), w.getTime());
}

void SteamNozzle::steam(WetIngredient& wi) {
    printf("Молочный продукт поступил в форсунок! Температура: %d Время: %d\n", wi.getTemperature(), wi.getTime());
    int toAdd = 65 - wi.getTemperature();
    wi.setTemperature(wi.getTemperature()+toAdd);
    wi.setTime(wi.getTime()+toAdd);
    printf("Молочный продукт нагрелся в форсунке! Температура: %d Время: %d\n", wi.getTemperature(), wi.getTime());
}

void SteamNozzle::mix(DryIngredient& ingredient) {
    // 
}

void SteamNozzle::add(Ingredient& ingredient) {
    // 
}

void CoffeeMachine::prepareCoffee() {
    // 
}
