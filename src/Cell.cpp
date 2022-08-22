#include "Cell.h"

Cell::Cell(const size_t x, const size_t y)
    : isFood(false), isSnake(false), x(x), y(y) {
    sprite.setSize(sf::Vector2f(50.f, 50.f));
    sprite.setPosition(sf::Vector2f(x * 60, y * 60));
    sprite.setFillColor(sf::Color::Black);
    sprite.setOutlineThickness(2.f);
    sprite.setOutlineColor(sf::Color::White);
}

bool Cell::isEmpty() {
    return !isFood && !isSnake;
}
