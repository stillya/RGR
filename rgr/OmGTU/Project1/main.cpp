
#define SFML_NO_DEPRECATED_WARNINGS

#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "headers/menu.h"
#include <windows.h>

using namespace std;

void drawAnimtaion(sf::RenderWindow& window);

int main() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 2.0;

    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML window", sf::Style::None, settings);
    
    window.setKeyRepeatEnabled(false);

    drawAnimtaion(window);

    window.create(sf::VideoMode(1200, 800), "SFML window", sf::Style::None, settings);

    Menu menu({ 250, 500 });

    menu.mainLoop(window);

}


void drawAnimtaion(sf::RenderWindow& window) {

    bool change = true;

    sf::Texture logob;
    sf::Texture logoy;

    if (!logob.loadFromFile("images/logo_black.png")) {
        exit(1);
    }
    if (!logoy.loadFromFile("images/logo_yellow.png")) {
        exit(1);
    }

    sf::Sprite sp;
    sf::Sprite ps;
    sp.setTexture(logob);
    ps.setTexture(logoy);

    sp.scale(1,1);
    ps.scale(1, 1);

    int logoWidth = sp.getGlobalBounds().width;
    int logoHeight = sp.getGlobalBounds().height;

    window.create(sf::VideoMode(logoWidth, logoHeight), "SFML", sf::Style::None); // <- Important!! Style=None removes title

    sf::Clock timer;
    sf::Time time = timer.restart();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {}

        time += timer.restart();
        if (time >= sf::seconds(2.f)) {
            window.close();
        }

        window.clear();
        if (change) {
            window.draw(sp);
            change = false;
        }
        else {
            window.draw(ps);
            change = true;
        }
        window.display();
        Sleep(150);
    }
}

