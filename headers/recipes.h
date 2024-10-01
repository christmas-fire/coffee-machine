#ifndef RECIPES_H
#define RECIPES_H

#include "coffee_machine.h"
#include "ingredients.h"
#include "cstdio"
#include "string"
#include <map>



class Recipe {
private:
    std::string name;
    std::map<std::string, unsigned> ingredients;
public:
    void setName(std::string n);
    std::string getName() const;
    void setIngredients(std::map<std::string, unsigned> ing);
    std::map<std::string, unsigned> getIngredients() const;
};

void parcer(std::string filename);


#endif // RECIPES_H