#ifndef RECIPES_H
#define RECIPES_H

#include "coffee_machine.h"
#include "ingredients.h"
#include "cstdio"
#include "string"
#include <map>
#include <vector>

class Recipe {
private:
    std::string name;
    std::map<std::string, unsigned> ingredients;
public:
    void setName(std::string n);
    std::string getName() const;
    void setIngredients(std::map<std::string, unsigned>& ing);
    std::map<std::string, unsigned> getIngredients() const;
};

class Parser {
public:
    void parse(std::string filename, std::vector<Recipe>& r);
};

class Print {
public:
    void printMap(std::map<std::string, unsigned> ingredients);
    void printVector(std::vector<Recipe> r);
};

#endif // RECIPES_H
