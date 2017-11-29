//
//  Organism.cpp
//  Game of Life
//
//  Created by Julio Sandino on 11/23/17.
//  Copyright © 2017 Julio Sandino. All rights reserved.
//

#include "Organism.hpp"
#include <iostream>

Organism::Organism(vector<vector<int> > starter) {
    for (int i = 0; i < starter.size(); i++) {
        cellArray.push_back(vector<Cell> (starter[i].size()));
    }
    
    for (int row = 0; row < starter.size(); row++) {
        for (int col = 0; col < starter[row].size(); col++) {
            Cell* cell = &cellArray[row][col];
            cell->setColor(starter[row][col]);
            cell->setPos(cell->getPos().x + 10 * col, cell->getPos().y + 10 * row);
        }
    }
}

void Organism::draw(sf::RenderWindow *window) {
    for (int row = 0; row < cellArray.size(); row++) {
        for (int col = 0; col < cellArray.size(); col++) {
            Cell* cell = &cellArray[row][col];
            cell->draw(window);
        }
    }
}

void Organism::update() {
    
    std::vector<std::vector<Cell> > temp = cellArray;
    for (int row = 0; row < temp.size(); row++) {
        for (int col = 0; col < temp[row].size(); col++) {
            int surroundingCounter = 0;
            Cell* cell = &cellArray[row][col];
            
            //Middle Cells
            if (row != 0 && col != 0 && row != temp.size() - 1 && col != temp[row].size() - 1) {
                if (temp[row - 1][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row - 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row - 1][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row ][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
            //Top row middle Cells
            } else if (row == 0 && col != 0 && col != temp[row].size() - 1) {
                if (temp[row][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row ][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
            //Left column midddle Cells
            } else if (row != 0 && col == 0 && row != temp.size() - 1) {
                if (temp[row - 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row - 1][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row ][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
            //top left corner
            } else if (row == 0 && col == 0) {
                if (temp[row][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
            //Top Right Corner
            } else if (row == 0 && col == temp[row].size() - 1) {
                if (temp[row][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
            //Right Column middle Cells
            } else if (row != temp.size() - 1 && col == temp[row].size() - 1 && row != 0) {
                if (temp[row - 1][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row - 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row + 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
            //Bottom middle cells
            } else if (row == temp.size() - 1 && col != temp[row].size() - 1 && col != 0) {
                if (temp[row - 1][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row - 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row - 1][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row ][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
            //bottom right corner
            } else if (row == temp.size() - 1 && col == temp[row].size() - 1) {
                if (temp[row - 1][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row - 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row][col - 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
            //bottom left corner
            } else if (row == temp.size() - 1 && col == 0) {
                if (temp[row - 1][col].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row - 1][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
                if (temp[row ][col + 1].getColor() == sf::Color::Black) {
                    surroundingCounter++;
                }
            }
            
            
            if (cell->getColor() == sf::Color::White) {
                //empty cell being populated
                if (surroundingCounter == 3) {
                    cell->setColor(1);
                    std::cout << "[" << row <<"]"<< "populated " << surroundingCounter << std::endl;
                } else {
                    std::cout << "[" << row <<"]"<< "no pop" << surroundingCounter << std::endl;
                    continue;
                }
            } else if (cell->getColor() == sf::Color::Black) {
                //death by solitude
                if (surroundingCounter <= 1) {
                    cell->setColor(0);
                    std::cout << "[" << row <<"]"<< "solitude" << surroundingCounter  << std::endl;
                //survive
                } else if (surroundingCounter == 2 || surroundingCounter == 3) {
                    std::cout << "[" << row <<"]"<< "survive" << surroundingCounter << std::endl;
                    continue;
                //death by overpopulation
                } else if (surroundingCounter >= 4) {
                    std::cout << "[" << row <<"]"<< "overpopulation" << surroundingCounter << std::endl;
                    cell->setColor(0);
                }
            }
        }
    }
}

Cell Organism::getCell(int row, int col) {
    return cellArray[row][col];
}
