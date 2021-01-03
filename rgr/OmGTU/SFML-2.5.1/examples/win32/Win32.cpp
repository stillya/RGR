
#define SFML_NO_DEPRECATED_WARNINGS

#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "headers/menu.h"

using namespace std;

void drawCartesian(sf::RenderWindow& window);
void drawPlot(sf::RenderWindow& window, int startX, int startY);



int main() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::None, settings);

    window.setKeyRepeatEnabled(false);




    int menu = 0; // graph - 1, root = 2, integral = 3

    bool graph = false;
    bool root = false;
    bool integral = false;

    sf::Text menuGraph;
    sf::Text menuRoot;
    sf::Text menuIntegral;

    sf::Font font;

    if (!font.loadFromFile("fonts/arial.ttf")) {
        printf("ERROR!!!");
        return EXIT_FAILURE;
    }

    menuGraph.setCharacterSize(20);
    menuGraph.setString("Graph");
    menuGraph.setPosition(150, 450);
    menuGraph.setColor(sf::Color(100, 255, 255, 255));
    menuGraph.setFont(font);

    menuRoot.setCharacterSize(20);
    menuRoot.setString("Root");
    menuRoot.setPosition(300, 450);
    menuRoot.setColor(sf::Color(255, 255, 255, 255));
    menuRoot.setFont(font);

    menuIntegral.setCharacterSize(20);
    menuIntegral.setString("Integral");
    menuIntegral.setPosition(450, 450);
    menuIntegral.setColor(sf::Color(255, 255, 255, 255));
    menuIntegral.setFont(font);


    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                case sf::Keyboard::Left:
                    if (menu <= 0) {
                        printf("LEFT KEY");
                        printf(" %d", menu);
                    }
                    else {
                        menu--;
                    }
                    break;

                case sf::Keyboard::Right:
                    if (menu >= 2) {
                        printf("RIGHT KEY");
                    }
                    else {
                        menu++;
                    }
                    break;

                case sf::Keyboard::Return:
                    switch (menu) {
                    case 0:
                        graph = true;
                        root = false;
                        integral = false;
                        break;
                    case 1:
                        root = true;
                        integral = false;
                        graph = false;
                        break;
                    case 2:
                        integral = true;
                        root = false;
                        graph = false;
                        break;
                    default:
                        printf("ERROR");
                        break;
                    }
                    break;

                default:
                    break;
                }
            }
        }

        switch (menu) {
        case 0:
            menuGraph.setColor(sf::Color(100, 255, 255, 255));
            menuRoot.setColor(sf::Color(255, 255, 255, 255));
            menuIntegral.setColor(sf::Color(255, 255, 255, 255));
            break;
        case 1:
            menuRoot.setColor(sf::Color(100, 255, 255, 255));
            menuGraph.setColor(sf::Color(255, 255, 255, 255));
            menuIntegral.setColor(sf::Color(255, 255, 255, 255));
            break;
        case 2:
            menuIntegral.setColor(sf::Color(100, 255, 255, 255));
            menuRoot.setColor(sf::Color(255, 255, 255, 255));
            menuGraph.setColor(sf::Color(255, 255, 255, 255));
            break;
        }
        // Clear screen
        window.clear();

        window.draw(menuGraph);
        window.draw(menuRoot);
        window.draw(menuIntegral);

        if (graph) {
            drawCartesian(window);
            drawPlot(window, 400, 200);
        }


        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}


void drawCartesian(sf::RenderWindow& window) {

    sf::CircleShape triangle(7, 3);

    triangle.setPosition(800, 195);
    triangle.setRotation(90);

    const unsigned int N = 1000u;
    const unsigned int s = 500u;

    sf::VertexArray xCoord(sf::LinesStrip);
    for (unsigned int i = 0; i < N - 1; i++) {
        xCoord.append(sf::Vertex(sf::Vector2f(i, 200), sf::Color::Blue));
    }

    sf::VertexArray yCoord(sf::LinesStrip);
    for (unsigned int i = 0; i < 400 - 1; i++) {
        yCoord.append(sf::Vertex(sf::Vector2f(400, i), sf::Color::Blue));
    }

    window.draw(xCoord);
    window.draw(yCoord);
    window.draw(triangle);

}

sf::VertexArray funcResults(double iterationNumber, double startX, double startY, double startPoint, double endPoint, double grapRatio, double height, double (*computeFunc)(double)) {

    const double start = startPoint + startX;
    const double end = endPoint + startX;
    double step = (end - start) / iterationNumber;

    sf::VertexArray func(sf::LineStrip);
    for (double i = 0; i <= endPoint * grapRatio; i += step * grapRatio) {
        func.append(sf::Vertex(sf::Vector2f(i + start, (computeFunc((i) / grapRatio) * height + startY)), sf::Color::White));
        printf("%f %f \n\n\n", i, computeFunc(i));
    }

    return func;
}

double cosFunc(double x) { //(pow(x + 5, 3) * (1 + (pow(sin(x), 2))));
    return -(pow(x + 5, 3) * (1 + (pow(sin(x), 2))));
}

void drawPlot(sf::RenderWindow& window, int startX, int startY) {

    sf::VertexArray func = funcResults(200000, startX, startY, 0, acos(-1.0), 10, 0.3, cosFunc); //PI

   // printf("FIRST X - %d, Y - %d \n", func[0].position.x, func[0].position.y);

    window.draw(func);

}
