#pragma once

#include <SFML/Graphics.hpp>
#include "point.h"

const int TRIANGLE = 3;
 

class Plot {
public:
	bool isDraw = false;

	Plot(double x, double y, sf::Color);
	~Plot();

	void drawCartesian(sf::RenderWindow& window, int xSize, int ySize);
	void drawPlot(sf::RenderWindow& window, sf::Color color, double startPoint, double endPoint, double grapRatio, double height, double (*computeFunc)(double));

private:
	Point center;
	sf::Color color;
	sf::VertexArray* verts;

	sf::VertexArray plotVertices(double iterationNumber, sf::Color color, double startPoint, double endPoint, double grapRatio, double height, double (*computeFunc)(double));
	sf::CircleShape drawArrows(int xSize, int ySize, Coord coord);
};