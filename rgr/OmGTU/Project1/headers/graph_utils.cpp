#include "graph_utils.h"

void drawFrame(sf::RenderWindow& window, Point firstPosition, Point secondPosition) {
	sf::VertexArray cadreFirst(sf::LineStrip);

	cadreFirst.append(sf::Vertex(sf::Vector2f(firstPosition.x + paddingUpper, firstPosition.y + paddingLeft), sf::Color::White));
	cadreFirst.append(sf::Vertex(sf::Vector2f(secondPosition.x + paddingBottom, secondPosition.y + paddingLeft), sf::Color::White));
	cadreFirst.append(sf::Vertex(sf::Vector2f(secondPosition.x + paddingBottom, secondPosition.y + paddingRight), sf::Color::White));
	cadreFirst.append(sf::Vertex(sf::Vector2f(firstPosition.x + paddingUpper, firstPosition.y + paddingRight), sf::Color::White));
	cadreFirst.append(sf::Vertex(sf::Vector2f(firstPosition.x + paddingUpper, firstPosition.y + paddingLeft), sf::Color::White));

	sf::VertexArray seperateLine(sf::LineStrip);

	seperateLine.append(sf::Vertex(sf::Vector2f(secondPosition.x + paddingSeperate, firstPosition.y + paddingLeft), sf::Color::White));
	seperateLine.append(sf::Vertex(sf::Vector2f(secondPosition.x + paddingSeperate, secondPosition.y + paddingRight), sf::Color::White));

	window.draw(cadreFirst);
	window.draw(seperateLine);
}
