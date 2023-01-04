#ifndef GRID_H
#define GRID_H

#include <cstdint>
#include <list>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

#include "Cell.h"

typedef std::pair<int, int> Point;

struct PointHash {
    size_t operator()(const Point &point) const {
        return std::hash<std::string>{}(std::to_string(point.first) +
                                        std::to_string(point.second));
    }
};

enum Direction : uint8_t { UP, DOWN, LEFT, RIGHT };

struct Grid : sf::Drawable {
    Direction direction;

    static const int GRID_SIZE = 80;

    std::vector<std::vector<Cell>> grid;
    std::vector<Point> emptyCells;
    std::list<Point> snake;
    std::unordered_map<Point, size_t, PointHash> emptyCellsMap;

    Grid();

    /**
     * @brief Main game logic
     *
     */
    void update();

    /**
     * @brief Update snake movement direction based on key event
     *
     * @param key
     */
    void updateDirection(const sf::Keyboard::Key key);

    void draw(sf::RenderTarget &window, sf::RenderStates states) const;

   private:
    std::random_device dev;
    std::mt19937 generator;

    const Point getRandomEmptyCell();

    const Point moveSnake() const;

    void setFood(const Point &cell);

    void setSnake(const Point &cell);

    void setEmpty(const Point &cell);

    static bool checkBounds(const Point &point);
};

#endif /* GRID_H */
