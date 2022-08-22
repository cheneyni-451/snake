#include "Grid.h"

#include <algorithm>
#include <iostream>
#include <random>

Grid::Grid() {
    generator = std::mt19937(dev());

    grid = std::vector<std::vector<Cell>>(GRID_SIZE);

    for (size_t row = 0; row < GRID_SIZE; ++row) {
        for (size_t col = 0; col < GRID_SIZE; ++col) {
            grid[row].emplace_back(col, row);

            // Middle cell set as snake
            // The rest are added to `emptyCells`
            if (col == GRID_SIZE / 2 && row == GRID_SIZE / 2) {
                grid[row][col].isSnake = true;
                grid[row][col].sprite.setFillColor(sf::Color::Green);
                snake.emplace_back(col, row);
            } else {
                emptyCells.emplace_back(col, row);
            }
        }
    }

    direction = Direction::UP;

    // TODO: randomly select food location
    const auto [x, y] = getRandomEmptyCell();
    Cell &randCell = grid[y][x];
    randCell.isFood = true;
    randCell.sprite.setFillColor(sf::Color::Red);
}

const Point Grid::getRandomEmptyCell() {
    std::uniform_int_distribution<size_t> distribution(0,
                                                       emptyCells.size() - 1);
    size_t randomIndex = distribution(generator);

    std::swap(emptyCells[randomIndex], emptyCells.back());
    const Point pointCopy = emptyCells.back();
    emptyCells.pop_back();

    return pointCopy;
}
