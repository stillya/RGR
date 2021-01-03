#pragma once

#include <SFML/Graphics.hpp>
#include "point.h"	

const double paddingUpper = -20;
const double paddingBottom = 105;
const double paddingLeft = -20;
const double paddingRight = 55;

const double paddingSeperate = -10;


void drawFrame(sf::RenderWindow& window, Point firstPosition, Point secondPosition);