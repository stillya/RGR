#include "headers/plot.h"


Plot::Plot(double x, double y, sf::Color color) {
	this->center = { x, y };
    this->color = color;
}

void Plot::drawCartesian(sf::RenderWindow& window, int xSize, int ySize) {

    Coord coordX(X);
    Coord coordY(Y);

    int initX = this->center.x - (xSize / 2);
    int initY = this->center.y - (ySize / 2);

    sf::VertexArray xCoord(sf::LinesStrip);
    for (unsigned int i = initX; i < initX + xSize; i++) {
        xCoord.append(sf::Vertex(sf::Vector2f(i, this->center.y), this->color));
    }

    sf::VertexArray yCoord(sf::LinesStrip);
    for (unsigned int i = initY; i < initY + ySize; i++) {
        yCoord.append(sf::Vertex(sf::Vector2f(this->center.x, i), this->color));
    }

    window.draw(xCoord);
    window.draw(yCoord);
    window.draw(this->drawArrows(xCoord[xCoord.getVertexCount() - 1].position.x, xCoord[0].position.y, coordX));
    window.draw(this->drawArrows(yCoord[0].position.x, yCoord[0].position.y, coordY));
}

void Plot::drawPlot(sf::RenderWindow& window, sf::Color color, double startPoint, double endPoint, double grapRatio, double height, double (*computeFunc)(double)) {

    sf::VertexArray func = this->plotVertices(20, color, startPoint, endPoint, grapRatio, height, computeFunc); //PI

    window.draw(func);
}

sf::VertexArray Plot::plotVertices(double iterationNumber, sf::Color color, double startPoint, double endPoint, double grapRatio, double height, double (*computeFunc)(double)) {
    
    if (this->verts == nullptr) {
        const double start = startPoint + this->center.x;
        const double end = endPoint + this->center.x;
        double step = (end - start) / iterationNumber;

        sf::VertexArray* func = new sf::VertexArray(sf::LineStrip);
        for (double i = startPoint; i <= endPoint * grapRatio; i += step * grapRatio) {
            func->append(sf::Vertex(sf::Vector2f(i + start, (-computeFunc((i) / grapRatio) * height + this->center.y)), color));
            printf("X - %f; Y - %f \n\n\n", i, computeFunc(i));
        }

        return *func;

    }
    else {
        return *verts;
    }
}

sf::CircleShape Plot::drawArrows(int xSize, int ySize, Coord coord) {

    sf::CircleShape triangle(7, TRIANGLE);

    switch (coord) {
    case X:
        triangle.setPosition(xSize, this->center.y - 6);
        triangle.setRotation(90);
        break;
    case Y:
        triangle.setPosition(this->center.x - 6, ySize);
        triangle.setRotation(0);
        break;
    default:
        break;
    }

    return triangle;

}

Plot::~Plot() {

    delete this->verts;
}