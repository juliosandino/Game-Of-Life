//
//  Cell.hpp
//  Game of Life
//
//  Created by Julio Sandino on 11/22/17.
//  Copyright © 2017 Julio Sandino. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"

class Cell {
public:
    Cell();
    ~Cell() {};
    
    void draw(sf::RenderWindow *window);
    void setPos(float x, float y);
    void setColor(int n);
    sf::Color getColor();
    sf::Vector2f getPos();
    
private:
    sf::CircleShape body;
};

#endif /* Cell_hpp */
