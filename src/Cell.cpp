#include "Cell.h"

Cell::Cell(const size_t x, const size_t y) : type(CellType::Empty), x(x), y(y) {
    sprite.setSize(sf::Vector2f(50.f, 50.f));
    sprite.setPosition(sf::Vector2f(x * 60, y * 60));
    sprite.setFillColor(sf::Color::Black);
    sprite.setOutlineThickness(2.f);
    sprite.setOutlineColor(sf::Color::White);
}

void Cell::setFood() {
    type = CellType::Food;

    sprite.setFillColor(sf::Color::Red);
}

void Cell::setSnake() {
    type = CellType::Snake;

    sprite.setFillColor(sf::Color::Green);
}

void Cell::setEmpty() {
    type = CellType::Empty;

    sprite.setFillColor(sf::Color::Black);
}

void Cell::draw(sf::RenderTarget *window) const {
    window->draw(sprite);
}
