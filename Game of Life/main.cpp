#include <SFML/Graphics.hpp>
#include <cmath>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Cell.hpp"
#include "Grid.hpp"
#include "Organism.hpp"
#include <iostream>
#include <vector>
using std::vector;

vector<vector<int> > pictureToVector(std::string image_path);


int main(int, char const**)
{
    //Test Vector with values
    vector<vector<int> > test;
    
    for (int i = 0; i < 60; i++){
        test.push_back(vector<int> (80, 0));
    }
    
    test[0][0] = 0;
    test[0][1] = 0;
    test[0][2] = 1;
    test[0][3] = 0;
    //--
    test[1][0] = 1;
    test[1][1] = 0;
    test[1][2] = 1;
    test[1][3] = 0;
    //--
    test[2][0] = 0;
    test[2][1] = 1;
    test[2][2] = 1;
    test[2][3] = 0;
    //--

    
    //Window initialization and settings
    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life", sf::Style::Default, settings);
    sf::Clock clock;
    const float FPS = 60;
    
    Cell cell;
    Grid grid;
    Organism organism(test);
    
    
    //run program as long as window is open
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            //"close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        if (clock.getElapsedTime().asMilliseconds() > 1000) {
            organism.update();
            clock.restart();
        }
        
        // clear the window with white color
        window.clear(sf::Color::White);
        
        //Drawing to the screen
        organism.draw(&window);
        grid.draw(&window);
        
        //end the current frame
        window.display();
        
    }
    
    return 0;
}

vector<vector<int> > pictureToVector(std::string image_path) {
    sf::Image image;
    if (!image.loadFromFile(resourcePath() + image_path)) {
        throw EXIT_FAILURE;
    }
    
}

