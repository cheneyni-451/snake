#ifndef GRID_H
#define GRID_H

#include <cstdint>
#include <random>
#include <vector>

#include "Cell.h"

typedef std::pair<size_t, size_t> Point;

enum Direction : uint8_t { UP, DOWN, LEFT, RIGHT };

struct Grid {
    Direction direction;

    static const size_t GRID_SIZE = 10;

    std::vector<std::vector<Cell>> grid;
    std::vector<Point> emptyCells;
    std::vector<Point> snake;

    Grid();

   private:
    std::random_device dev;
    std::mt19937 generator;

    const Point getRandomEmptyCell();
};

#endif /* GRID_H */
