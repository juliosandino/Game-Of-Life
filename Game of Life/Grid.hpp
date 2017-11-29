//
//  Grid.hpp
//  Game of Life
//
//  Created by Julio Sandino on 11/23/17.
//  Copyright © 2017 Julio Sandino. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include <vector>

class Grid {
public:
    Grid();
    ~Grid() {};
    void draw(sf::RenderWindow *window);
    
private:
    float spaceBetween;
};

#endif /* Grid_hpp */
