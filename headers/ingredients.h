#ifndef INGREDIENTS_H
#define INGREDIENTS_H

class Ingredient {
private:
    int temperature; // температура
    int amount; // количество
    int time; // время, которое они требуют
public:
    Ingredient() : temperature(24), amount(0), time(0) {}
    void setTemperature(int t);
    int getTemperature() const;
    void setAmount(int a);
    int getAmount() const;
    void setTime(int t);
    int getTime() const;
};

class WetIngredient : public Ingredient {
    // мокрые ингредиенты
};
 
class DryIngredient : public Ingredient {
    // сухие ингредиенты
};

class CoffeeBeans : public DryIngredient {
private:
    bool is_grinded;
public:
    CoffeeBeans() : is_grinded(false) {}
    void setStatus(bool s);
    bool getStatus() const;
};

class Sugar : public DryIngredient {
    // сахар
};

class Milk : public WetIngredient {
    // молоко
};

class Water : public WetIngredient {
    // вода
};

class Cream : public WetIngredient {
    // сливки
};

#endif // INGREDIENTS_H