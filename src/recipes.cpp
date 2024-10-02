#include "recipes.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void Recipe::setName(std::string n) {
    name = n;
}

std::string Recipe::getName() const {
    return name;
}

void Recipe::setIngredients(std::map<std::string, unsigned>& ing) {
    ingredients = ing;
}

std::map<std::string, unsigned> Recipe::getIngredients() const {
    return ingredients;
}

void Parser::parse(std::string filename, std::vector<Recipe>& r) {
    std::ifstream file;  // поток для чтения
    file.open(filename); // окрываем файл для чтения
    
    std::string line;

    while(std::getline(file, line)) {    
        Recipe recipe;
        std::string name;
        std::map<std::string, unsigned> ingredients;

        for(auto li:line) {          
            if (li == ':') break;
            name += li;
        }
        recipe.setName(name);

        line = line.substr(line.find(':') + 1, line.size());
        std::string name_ing;
        std::string count_ing;
        std::map<std::string, unsigned> ing;
        int count = std::count(line.begin(), line.end(), ',');
        for(int i = 0; i < count + 1; i++) {
            name_ing = line.substr(0, line.find('('));
            line = line.substr(line.find('(') + 1, line.size());
            count_ing = line.substr(0, line.find(')'));
            int n = std::stoi(count_ing);
            ing[name_ing] = n;
            if(i < count) {
                line = line.substr(line.find(')') + 2, line.size());
            }
        }
        recipe.setIngredients(ing);
        r.push_back(recipe);
    }
    file.close();
}
