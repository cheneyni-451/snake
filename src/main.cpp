#include <SFML/Graphics.hpp>
#include <queue>

#include "Grid.h"

int main() {
    sf::Clock clock;
    const double TIMESTEP = 0.375;
    double lappedTime = 0.0;

    sf::RenderWindow window(sf::VideoMode(200, 200), "Snake!");

    Grid grid = Grid();

    std::queue<sf::Event> keyPresses;

    while (window.isOpen()) {
        lappedTime += clock.restart().asSeconds();

        sf::Event event;

        while (lappedTime >= TIMESTEP) {
            lappedTime -= TIMESTEP;

            if (!keyPresses.empty()) {
                const sf::Event &keyPress = keyPresses.front();
                grid.updateDirection(keyPress.key.code);
                keyPresses.pop();
            }

            grid.update();
        }

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    window.setView(sf::View(sf::FloatRect(
                        0, 0, event.size.width, event.size.height)));
                    break;
                case sf::Event::KeyPressed:
                    keyPresses.push(event);
                    break;
                default:
                    break;
            }
        }

        window.clear();
        grid.draw(&window);
        window.display();
    }

    return 0;
}
