#include "ingredients.h"

void Ingredient::setTemperature(int t) {
    temperature = t;
}

int Ingredient::getTemperature() const {
    return temperature;
}

void Ingredient::setAmount(int a) {
    amount = a;
}

int Ingredient::getAmount() const {
    return amount;
}

void Ingredient::setTime(int t) {
    time = t;
}

int Ingredient::getTime() const {
    return time;
}

void CoffeeBeans::setStatus(bool s) {
    is_grinded = s;
}

bool CoffeeBeans::getStatus() const {
    return is_grinded;
}