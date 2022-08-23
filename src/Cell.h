#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include <cstdlib>

struct Cell : sf::Drawable {
    enum CellType : uint8_t { Empty, Food, Snake };
    CellType type;
    size_t x;
    size_t y;
    sf::RectangleShape sprite;

    Cell(const size_t x, const size_t y);

    void setFood();

    void setSnake();

    void setEmpty();

    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};

#endif /* CELL_H */
