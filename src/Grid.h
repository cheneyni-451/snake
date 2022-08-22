#ifndef GRID_H
#define GRID_H

#include <cstdint>
#include <list>
#include <random>
#include <vector>

#include "Cell.h"

typedef std::pair<int, int> Point;

enum Direction : uint8_t { UP, DOWN, LEFT, RIGHT };

struct Grid {
    Direction direction;

    static const int GRID_SIZE = 10;

    std::vector<std::vector<Cell>> grid;
    std::vector<Point> emptyCells;
    std::list<Point> snake;

    Grid();

    void update();

    void updateDirection(const sf::Keyboard::Key key);

    void draw(sf::RenderTarget *window);

   private:
    std::random_device dev;
    std::mt19937 generator;

    const Point getRandomEmptyCell();

    const Point moveSnake() const;

    void setFood(const Point &cell);

    void setSnake(const Point &cell);

    void setEmpty(const Point &cell);

    bool checkBounds() const;
};

#endif /* GRID_H */
