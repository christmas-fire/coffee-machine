#include <iostream>
#include "coffee_machine.h"
#include "ingredients.h"
#include "recipes.h"

using namespace std;

int main() {
    Parser parser;
    vector<Recipe> r;
    parser.parse("recipes.txt", r);
    cout << r[0].getName();
    if (r[0].getName() == "Латте") {
        Milk m1, m2;
        CoffeeBeans c;

        CoffeeGrinder cg;
        Group gr;
        SteamNozzle sn;

        cg.grind(c);
        gr.boil(c);
        sn.steam(m1);
        sn.steam(m2);

        int time = c.getTime() + m1.getTime() + m2.getTime();
        cout << "Общее время: " << time;
    } 

    return 0;
}
