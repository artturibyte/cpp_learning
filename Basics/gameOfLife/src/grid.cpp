
#include "grid.h"


void grid::create(int row, int col) {
    cells[row][col].create();
}

void grid::draw() {
    // ANSI control command
    // \x1b means "escape"
    // Escape[2J clears the screen and returns the cursor to the "home" position
    std::cout << "\x1b[2J";

    for (int row = 0; row < rowmax; ++row) {
        for (int column = 0; column < colmax; ++column) {
            cells[row][column].draw(row, column);
        }
    }
}

void grid::randomize() {
    const int factor = 5;
    const int cutoff = RAND_MAX/factor;
    time_t now;
    time(&now);

    for (int row = 0; row < rowmax; ++row)
    {
        for (int col = 0; col < colmax; ++col)
        {
            if (rand() / cutoff == 0) {
                create(row, col);
            }
        }  
    }
}

bool grid::will_survive(int row, int col) {
    if (!cells[row][col].is_alive()) {
        return false;
    }

    //find number of living neighbours
    // x x x
    // x 0 x
    // x x x

    int neighbours = cells[row - 1][col - 1].is_alive() +
                    cells[row - 1][col].is_alive() +
                    cells[row + 1][col].is_alive() +
                    cells[row][col + 1].is_alive() +
                    cells[row][col - 1].is_alive() +
                    cells[row + 1][col + 1].is_alive() +
                    cells[row + 1][col - 1].is_alive() +
                    cells[row - 1][col + 1].is_alive();

    if (neighbours < min_neighbours || neighbours > max_neighbours) {
        return false;
    }

    return true;
}

bool grid::will_create(int row, int col) {
    //already cell in position
    if (cells[row][col].is_alive()) {
        return false;
    }

    //find number of living neighbours
    // x x x
    // x 0 x
    // x x x

    int parents = cells[row - 1][col - 1].is_alive() +
                    cells[row - 1][col].is_alive() +
                    cells[row + 1][col].is_alive() +
                    cells[row][col + 1].is_alive() +
                    cells[row][col - 1].is_alive() +
                    cells[row + 1][col + 1].is_alive() +
                    cells[row + 1][col - 1].is_alive() +
                    cells[row - 1][col + 1].is_alive();

    if (parents < min_parents || parents > max_parents) {
        return false;
    }

    return true;
}

void grid::update(const grid& next) {
    for (int row = 0; row < rowmax; ++row)
    {
        for (int col = 0; col < colmax; ++col)
        {
            cells[row][col] = next.cells[row][col];
        }  
    }
}

void calculate(grid& old_gen, grid& next_gen) {
    for (int row = 0; row < rowmax; ++row)
    {
        for (int col = 0; col < colmax; ++col)
        {
            if (old_gen.will_survive(row, col) || old_gen.will_create(row, col)) {
                next_gen.create(row, col);
            }
        }  
    }
}