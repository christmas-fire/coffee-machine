#include "coffee_machine.h"

void CoffeeGrinder::grind(CoffeeBeans& c) {
    int time = 14 + rand() % (19 - 14 + 1);
    c.setTime(c.getTime() + time);
    c.setStatus(true);
}

void Group::boil(CoffeeBeans& c) {
    if (c.getStatus()) {
        int time = 19 + rand() % (24 - 19 + 1);
        c.setTime(c.getTime() + time);
    } else {
        return;
    }
}

void Boiler::heat(Water& w) {
    int toAdd = 100 - w.getTemperature();
    w.setTemperature(w.getTemperature() + toAdd);
    w.setTime(w.getTime() + toAdd);
}

void SteamNozzle::steam(WetIngredient& wi) {
    int toAdd = (65 + rand() % (70 - 65 + 1)) - wi.getTemperature();
    wi.setTemperature(wi.getTemperature() + toAdd);
    wi.setTime(wi.getTime() + toAdd);
}

void SteamNozzle::mix(DryIngredient& di) {
    di.setTime(di.getTime() + 10);
}

void SteamNozzle::add(Ingredient& ingredient, int amount) {
    //
}

int CoffeeMachine::prepareCoffee(Recipe& r) {
    r.getIngredients();
    int allTime = 0;
    for(auto ingredient : r.getIngredients()) {
        if(ingredient.first == "молоко" || ingredient.first == "сливки") {
            srand(time(NULL));
            for(int i = 0; i < ingredient.second; i++) {
                Milk milk;
                nozzle.steam(milk);
                allTime += milk.getTime();
            }
        }
        else if(ingredient.first == "кофе") {
            srand(time(NULL));
            for(int i = 0; i < ingredient.second; i++) {           
                CoffeeBeans cb;
                grinder.grind(cb);
                group.boil(cb);
                allTime += cb.getTime();
            }
        }
        else if(ingredient.first == "вода") {
            for(int i = 0; i < ingredient.second; i++) {
                Water w;
                boiler.heat(w);
                allTime += w.getTime();
            }
        }
        else if(ingredient.first == "ванильный сахар") {
            for(int i = 0; i < ingredient.second; i++) {
                DryIngredient sugar;
                nozzle.mix(sugar);
                allTime += sugar.getTime();
            }
        }
    }
    return allTime;
}
