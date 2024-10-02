#include <iostream>
#include "coffee_machine.h"
#include "ingredients.h"
#include "recipes.h"
#include "menu.h"

using namespace std;

int main() {
    Parser parser;
    std::vector<Recipe> r;
    parser.parse("recipes.txt", r);
    Menu menu;
    CoffeeMachine cm;
    menu.start(r, cm);
    return 0;
}
