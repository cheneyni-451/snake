#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include <cstdlib>

struct Cell {
    bool isFood;
    bool isSnake;
    size_t x;
    size_t y;
    sf::RectangleShape sprite;

    Cell(const size_t x, const size_t y);

    bool isEmpty();
};

#endif /* CELL_H */
