#include "headers/menu.h"

const char* graphMenuName = "Graph";
const char* rootMenuName = "Root";
const char* integralMenuName = "Integral";
const double interval = 200;

double anotherFunc(double x) { //(pow(x + 5, 3) * (1 + (pow(sin(x), 2))));
    return (pow(x + 5, 3) * (1 + (pow(sin(x), 2))));
}

double cosFunc(double x) {
    return cos(x);
}

double rootFunc(double x) {
    return 0.5 + cos(x) - 2 * x * sin(x);
}

double integralFunc(double x) {
    return pow(x, 0.5) * sin(x);
}

Menu::Menu(Point coords)
    : plot(600, 250, sf::Color::Color(100, 112, 219)), root(700, 500, sf::Color::White, "fonts/classic.ttf", 23), integral(800, 500, sf::Color::White, "fonts/classic.ttf", 23) {

    if (!this->elements.graphTexture.loadFromFile("images/graph_button.png")) {
        printf("ERROR! Can't load texture! \n\n\n");
        exit(-1);
    }

    if (!this->elements.rootTexture.loadFromFile("images/root_button.png")) {
        printf("ERROR! Can't load texture! \n\n\n");
        exit(-1);
    }

    if (!this->elements.integralTexture.loadFromFile("images/integral_button.png")) {
        printf("ERROR! Can't load texture! \n\n\n");
        exit(-1);
    }

    if (!this->elements.backgroundTexture.loadFromFile("images/background_image.png")) {
        printf("ERROR! Can't load texture! \n\n\n");
        exit(-1);
    }

    this->elements.background.setTexture(this->elements.backgroundTexture);
    this->elements.menuGraph.setTexture(this->elements.graphTexture);
    this->elements.menuRoot.setTexture(this->elements.rootTexture);
    this->elements.menuIntegral.setTexture(this->elements.integralTexture);

    this->elements.menuGraph.setPosition(coords.x, coords.y);
    this->elements.menuRoot.setPosition(coords.x + interval, coords.y);
    this->elements.menuIntegral.setPosition(coords.x + interval * 2, coords.y);

    this->elements.menuGraph.setColor(sf::Color::White);
    this->elements.menuRoot.setColor(sf::Color(255, 255, 255, 128));
    this->elements.menuIntegral.setColor(sf::Color(255, 255, 255, 128));
    this->elements.background.setColor(sf::Color(255, 255, 255, 128));

    this->elements.menuGraph.setScale(3, 3);
    this->elements.menuRoot.setScale(3, 3);
    this->elements.menuIntegral.setScale(3, 3);

}


void Menu::mainLoop(sf::RenderWindow& window) {

    int menuCounter = 0; // graph - 0, root = 1, integral = 2

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
                    if (menuCounter <= 0) {
                        printf("LEFT KEY \n");
                    }
                    else {
                        menuCounter--;
                        this->chooseElement(menuCounter, event.key.code);
                    }
                    break;

                case sf::Keyboard::Right:
                    if (menuCounter >= 2) {
                        printf("RIGHT KEY \n");
                    }
                    else {
                        menuCounter++;
                        this->chooseElement(menuCounter, event.key.code);
                    }
                    break;

                case sf::Keyboard::Return:
                    this->chooseElement(menuCounter, event.key.code);
                    break;

                case sf::Keyboard::Escape:
                    window.close();
                    break;

                default:
                    break;
                }
            }
        }

        window.clear();

        window.draw(this->elements.background);
        window.draw(this->elements.menuGraph);
        window.draw(this->elements.menuRoot);
        window.draw(this->elements.menuIntegral);

        if (plot.isDraw) {
            this->plot.drawCartesian(window, 550, 500);
            this->plot.drawPlot(window, sf::Color::White, 0, acos(-1.0), 10, 0.3, anotherFunc);
            this->plot.drawPlot(window, sf::Color::Red, 0, acos(-1.0), 60, 60, cosFunc);
        }
        if (root.isDraw) {
            this->plot.drawCartesian(window, 550, 500);
            this->plot.drawPlot(window, sf::Color::White, 3, 3.2, 20, 20, rootFunc);
            this->root.drawRoot(window, "0.5 + cos(x) - 2x * sin(x)", 3, 3.2, 0.001, rootFunc);
        }
        if (integral.isDraw) {
            this->plot.drawCartesian(window, 550, 500);
            this->integral.drawIntegral(window, "x^1/2 * sin(x)", 0, acos(-1), 3000, integralFunc);
            this->integral.drawSquare(window, 600, 250, 0, 2* acos(-1.0), 60, 30, integralFunc);
        }

        window.display();
    }
}


void Menu::chooseElement(int menuCounter, sf::Keyboard::Key key) {
    switch (menuCounter) {
    case 0:
        if (!(key == sf::Keyboard::Return)) {
            this->elements.menuGraph.setColor(sf::Color::White);
            this->elements.menuRoot.setColor(sf::Color(255, 255, 255, 128));
            this->elements.menuIntegral.setColor(sf::Color(255, 255, 255, 128));

        }
        else {
            this->plot.isDraw = true;
            this->root.isDraw = false;
            this->integral.isDraw = false;
        }
        break;
    case 1:
        if (!(key == sf::Keyboard::Return)) {
            this->elements.menuGraph.setColor(sf::Color(255, 255, 255, 128));
            this->elements.menuRoot.setColor(sf::Color::White);
            this->elements.menuIntegral.setColor(sf::Color(255, 255, 255, 128));

        }
        else {
            this->plot.isDraw = false;
            this->root.isDraw = true;
            this->integral.isDraw = false;
        }
        break;
    case 2:
        if (!(key == sf::Keyboard::Return)) {
            this->elements.menuGraph.setColor(sf::Color(255, 255, 255, 128));
            this->elements.menuRoot.setColor(sf::Color(255, 255, 255, 128));
            this->elements.menuIntegral.setColor(sf::Color::White);

        }
        else {
            this->plot.isDraw = false;
            this->root.isDraw = false;
            this->integral.isDraw = true;
        }
        break;
    default:
        printf("ERROR \n");
        break;
    }

}
