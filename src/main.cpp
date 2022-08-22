#include <SFML/Graphics.hpp>

#include "Grid.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    Grid grid = Grid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    window.setView(sf::View(sf::FloatRect(
                        0, 0, event.size.width, event.size.height)));
                    break;
                default:
                    break;
            }
        }

        window.clear();
        for (const auto &row : grid.grid) {
            for (const Cell &cell : row) {
                window.draw(cell.sprite);
            }
        }
        window.display();
    }

    return 0;
}
