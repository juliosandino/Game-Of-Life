//
//  Grid.cpp
//  Game of Life
//
//  Created by Julio Sandino on 11/23/17.
//  Copyright © 2017 Julio Sandino. All rights reserved.
//

#include "Grid.hpp"

Grid::Grid() {
    spaceBetween = 10;
}

void Grid::draw(sf::RenderWindow *window) {
    
    for (int i = 0; i <= window->getSize().x; i += spaceBetween) {
        
        if (i <= window->getSize().y) {
            sf::RectangleShape hline(sf::Vector2f(window->getSize().x, 1));
            hline.setPosition(hline.getPosition().x, i);
            hline.setFillColor(sf::Color::Color(200, 200, 200, 255));
            
            window->draw(hline);
        }
        
        sf::RectangleShape vline(sf::Vector2f(window->getSize().y, 1));
        vline.setPosition(i ,vline.getPosition().y);
        vline.setFillColor(sf::Color::Color(200, 200, 200, 255));
        vline.rotate(90);
        
        window->draw(vline);
    }
}
