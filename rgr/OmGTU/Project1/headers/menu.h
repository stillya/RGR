#pragma once

#include <SFML/Graphics.hpp>
#include "plot.h"
#include "integral.h"
#include "plot.h"
#include "root.h"

typedef struct Elements {
	sf::Sprite background;
	sf::Sprite menuGraph;
	sf::Sprite menuRoot;
	sf::Sprite menuIntegral;

	sf::Texture backgroundTexture; 
	sf::Texture graphTexture;
	sf::Texture rootTexture;
	sf::Texture integralTexture;
} Elements;

class Menu {
public:

	Menu(Point coords);

	void mainLoop(sf::RenderWindow& window);

private:
	void chooseElement(int menuCounter, sf::Keyboard::Key key);

	Elements elements;
	Plot plot;
	Root root;
	Integral integral;
};