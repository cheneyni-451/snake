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
                snake.emplace_back(col, row);
                setSnake(snake.back());
            } else {
                emptyCells.emplace_back(col, row);
            }
        }
    }

    direction = Direction::UP;

    const Point &randPoint = getRandomEmptyCell();
    setFood(randPoint);
}

void Grid::update() {
    const Point newHead = moveSnake();
    if (!checkBounds()) {
        exit(1);
    }
    snake.push_front(newHead);
    const auto headIter =
        std::find(emptyCells.cbegin(), emptyCells.cend(), newHead);
    emptyCells.erase(headIter);

    const auto [col, row] = newHead;
    const Cell &headCell = grid[row][col];
    if (headCell.type == Cell::CellType::Empty) {
        const Point &tail = snake.back();
        emptyCells.push_back(tail);
        setEmpty(tail);
        snake.pop_back();
    } else if (headCell.type == Cell::CellType::Food) {
        const Point randPoint = getRandomEmptyCell();
        setFood(randPoint);
    } else {
        exit(1);
    }

    setSnake(newHead);
}

void Grid::updateDirection(const sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::W:
            [[fallthrough]];
        case sf::Keyboard::Up:
            if (direction != Direction::DOWN) {
                direction = Direction::UP;
            }
            break;
        case sf::Keyboard::S:
            [[fallthrough]];
        case sf::Keyboard::Down:
            if (direction != Direction::UP) {
                direction = Direction::DOWN;
            }
            break;
        case sf::Keyboard::A:
            [[fallthrough]];
        case sf::Keyboard::Left:
            if (direction != Direction::RIGHT) {
                direction = Direction::LEFT;
            }
            break;
        case sf::Keyboard::D:
            [[fallthrough]];
        case sf::Keyboard::Right:
            if (direction != Direction::LEFT) {
                direction = Direction::RIGHT;
            }
            break;
        default:
            break;
    }
}

void Grid::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (const auto &row : grid) {
        for (const Cell &cell : row) {
            window.draw(cell);
        }
    }
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

const Point Grid::moveSnake() const {
    Point newHead = snake.front();

    switch (direction) {
        case Direction::UP:
            newHead.second -= 1;
            break;
        case Direction::DOWN:
            newHead.second += 1;
            break;
        case Direction::LEFT:
            newHead.first -= 1;
            break;
        case Direction::RIGHT:
            newHead.first += 1;
            break;
        default:
            break;
    }

    return newHead;
}

void Grid::setFood(const Point &cell) {
    grid[cell.second][cell.first].setFood();
}

void Grid::setSnake(const Point &cell) {
    grid[cell.second][cell.first].setSnake();
}

void Grid::setEmpty(const Point &cell) {
    grid[cell.second][cell.first].setEmpty();
}

bool Grid::checkBounds() const {
    const auto [col, row] = snake.front();

    if (row < 0 || row >= GRID_SIZE) {
        return false;
    }

    if (col < 0 || col >= GRID_SIZE) {
        return false;
    }
    return true;
}
