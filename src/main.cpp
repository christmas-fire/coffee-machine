#include <iostream>
#include "coffee_machine.h"
#include "ingredients.h"
#include "recipes.h"

using namespace std;

int main() {
    CoffeeBeans c;
    CoffeeGrinder g;
    Group gr;
    Milk m;
    SteamNozzle st;
    g.grind(c);
    gr.boil(c);
    st.steam(m);
    cout << endl;
    int allTime = c.getTime()+m.getTime();
    cout << "Общее время: " << allTime << endl;

    parcer("recipes.txt");

    
    
    
    


    return 0;
}