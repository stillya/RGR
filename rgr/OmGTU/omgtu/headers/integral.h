#pragma once

#include <SFML/Graphics.hpp>
#include "point.h"
#include "graph_utils.h"


class Integral {
public:
	bool isDraw = false;

	Integral(double x, double y, sf::Color color, const char* fontName, size_t fontSize);

	void drawIntegral(sf::RenderWindow& window, const char* funcName, double startPoint, double endPoint, size_t numOfDot, double (*computeFunc)(double));
	void drawSquare(sf::RenderWindow& window, double initX, double initY, double startPoint, double endPoint, double graphRatio, double height, double(*computeFunc)(double));

private:
	Point center;
	sf::Color color; 
	sf::Text func; 
	sf::Text integral;
	sf::Font font; 

	double findIntegral(double startPoint, double endPont, size_t numOfDot, double(*computeFunc)(double));

};