#include "headers/root.h"
#include <SFML/Graphics.hpp>
#include <string.h>

const int interval = 300;

Root::Root(double x, double y, sf::Color color, const char* fontName, size_t fontSize) {

	this->center = { x, y };
	this->color = color;

	if (!this->font.loadFromFile(fontName)) {
		printf("ERROR! Can't load font! \n\n\n");
		exit(-1);
	}

	this->func.setFont(font);
	this->func.setCharacterSize(fontSize);
	this->func.setFillColor(this->color);
	this->func.setPosition(this->center.x, this->center.y);

	this->root.setFont(font);
	this->root.setCharacterSize(fontSize);
	this->root.setFillColor(this->color);
	this->root.setPosition(this->center.x + interval, this->center.y);
}

void Root::drawRoot(sf::RenderWindow& window, const char* funcName, double startPoint, double endPoint, double eps, double(*computeFunc)(double)) {

	this->func.setString(funcName);

	std::string result = std::to_string(this->findRoot(startPoint, endPoint, eps, computeFunc));
	
	this->root.setString(result);

	window.draw(this->func);
	window.draw(this->root);
	
	drawFrame(window, { this->func.getPosition().x, this->func.getPosition().y }, { this->root.getPosition().x, this->root.getPosition().y });
}

double Root::findRoot(double startPoint, double endPoint, double eps, double(*computeFunc)(double)) {

	double c;
	while ((endPoint - startPoint) / 2 > eps) {
		c = (startPoint + endPoint) / 2;
		if ((computeFunc(startPoint) * computeFunc(c)) > 0) startPoint = c;
		else endPoint = c;
	}
	return c; 
}

