#include <iostream>
#include "coffee_machine.h"
#include "ingredients.h"
#include "recipes.h"

using namespace std;

int main() {
    CoffeeBeans c;
    c.setStatus(true);
    cout << c.getTemperature() << endl;
    cout << c.getAmount() << endl;
    cout << c.getTime() << endl;
    cout << c.getStatus() << endl;
    return 0;
}