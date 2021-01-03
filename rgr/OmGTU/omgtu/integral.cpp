#include "headers/integral.h"

const int interval = 150;

Integral::Integral(double x, double y, sf::Color color, const char* fontName, size_t fontSize) {

	this->center = { x, y };
	this->color = color; 

	if (!this->font.loadFromFile(fontName)) {
		printf("ERROR! Can't load font \n\n\n");
		exit(-1);
	}

	this->func.setFont(font);
	this->func.setCharacterSize(fontSize);
	this->func.setFillColor(this->color);
	this->func.setPosition(this->center.x, this->center.y);

	this->integral.setFont(font);
	this->integral.setCharacterSize(fontSize);
	this->integral.setFillColor(this->color);
	this->integral.setPosition(this->center.x + interval, this->center.y);

}

void Integral::drawIntegral(sf::RenderWindow& window, const char* funcName, double startPoint, double endPoint, size_t numOfDot, double(*computeFunc)(double)) {

	this->func.setString(funcName);

	std::string result = std::to_string(this->findIntegral(startPoint, endPoint, numOfDot, computeFunc));

	printf("%s \n", result);

	this->integral.setString(result);

	drawFrame(window, { this->func.getPosition().x, this->func.getPosition().y }, { this->integral.getPosition().x, this->integral.getPosition().y });

	window.draw(this->func);
	window.draw(this->integral);
}

void Integral::drawSquare(sf::RenderWindow& window, double initX, double initY, double startPoint, double endPoint, double graphRatio, double height, double(*computeFunc)(double)) {

	const double start = startPoint + initX;
	const double end = endPoint + initX;
	double step = (end - start) / 1000;

	sf::VertexArray func(sf::LineStrip);
	for (double i = startPoint; i <= endPoint * graphRatio; i += step * graphRatio) {
		func.append(sf::Vertex(sf::Vector2f(i + start, (-computeFunc((i) / graphRatio) * height + initY)), sf::Color::White));
		printf("%f %f \n\n\n", i, computeFunc(i));
	}

	sf::VertexArray square(sf::LineStrip);
	for (int i = 0; i < func.getVertexCount() - 1; i++) {
		square.append(sf::Vertex(sf::Vector2f(func[i].position.x, func[i].position.y), sf::Color::White));
		square.append(sf::Vertex(sf::Vector2f(func[i].position.x, initY), sf::Color::White));
	}

	window.draw(func);
	window.draw(square);
}

double Integral::findIntegral(double startPoint, double endPont, size_t numOfDot, double(*computeFunc)(double)) {
	double step = endPont / numOfDot;
	double x = 0;
	double result = 0;

	for (int i = 0; i < numOfDot; i++) {
		result += computeFunc(x);
		x += step;
	}
	
	return result * step;
}
