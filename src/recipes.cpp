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

void Recipe::setIngredients(std::map<std::string, unsigned> ing) {
    ingredients = ing;
}

std::map<std::string, unsigned> Recipe::getIngredients() const {
    return ingredients;
}
void parcer(std::string filename) {
    std::ifstream file;  // поток для чтения
    file.open(filename); // окрываем файл для чтения
    
    std::string line;
    //std::string name;

    while(std::getline(file, line)) {    
        
        std::string name;
        std::map<std::string, unsigned> ingredients;

        for(auto li:line) {          
            if (li == ':') break;
            name += li;
        }

        std::cout << name << std::endl;

        line = line.substr(line.find(':') + 1, line.size());

        std::string name_ing;
        std::string count_ing;

        int count = std::count(line.begin(), line.end(), ',');
        for(int i = 0; i < count + 1; i++) {
            
            name_ing = line.substr(0, line.find('('));
            std::cout << name_ing << std::endl;
            line = line.substr(line.find('(') + 1, line.size());
            //std::cout << line << std::endl;

            count_ing = line.substr(0, line.find(')'));
            std::cout << count_ing << std::endl;

            if(i < count) {
                line = line.substr(line.find(')') + 2, line.size());
            }
            
            //std::cout << name_ing << " " << count_ing << " ";
        }
        std::cout << std::endl;

    }

    file.close();
}