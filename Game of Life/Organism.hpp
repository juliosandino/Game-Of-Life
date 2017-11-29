//
//  Organism.hpp
//  Game of Life
//
//  Created by Julio Sandino on 11/23/17.
//  Copyright © 2017 Julio Sandino. All rights reserved.
//

#ifndef Organism_hpp
#define Organism_hpp

#include <stdio.h>
#include <vector>
#include "Cell.hpp"
#include "SFML/Graphics.hpp"
using std::vector;

class Organism {
public:
    Organism(vector<vector<int> > starter);
    ~Organism() {};
    void draw(sf::RenderWindow *window);
    void update();
    Cell getCell(int row, int col);
    
private:
    vector<vector<Cell> > cellArray;
};

#endif /* Organism_hpp */
