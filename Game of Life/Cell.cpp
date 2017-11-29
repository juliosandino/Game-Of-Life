//
//  Cell.cpp
//  Game of Life
//
//  Created by Julio Sandino on 11/22/17.
//  Copyright © 2017 Julio Sandino. All rights reserved.
//

#include "Cell.hpp"
#include "cmath"

Cell::Cell() {
    body.setRadius(5 * sqrt(2));
    body.setPointCount(4);
    body.rotate(45);
    body.setPosition(body.getRadius() / 2, 0 - body.getRadius() / 2);
    body.setFillColor(sf::Color::Black);
}

void Cell::setPos(float x, float y) {
    body.setPosition(x, y);
}

void Cell::setColor(int n) {
    switch (n) {
        case 0:
            body.setFillColor(sf::Color::White);
            break;
        case 1:
            body.setFillColor(sf::Color::Black);
            break;
        default:
            body.setFillColor(sf::Color::Black);
            break;
    }
}

sf::Vector2f Cell::getPos() {
    return body.getPosition();
}

sf::Color Cell::getColor() {
    return body.getFillColor();
}

void Cell::draw(sf::RenderWindow *window) {
    window->draw(body);
}
