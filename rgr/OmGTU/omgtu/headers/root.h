#pragma once

#include <SFML/Graphics.hpp>
#include "point.h"
#include "graph_utils.h"


class Root {
public:
	bool isDraw = false;

	Root(double x, double y, sf::Color color, const char* fontName, size_t fontSize);

	void drawRoot(sf::RenderWindow& window, const char* funcName, double startPoint, double endPoint, double eps, double (*computeFunc)(double));

private:
	Point center;
	sf::Color color;
	sf::Text func;
	sf::Text root;
	sf::Font font;

	double findRoot(double startPoint, double endPoint, double eps, double (*computeFunc)(double));
};