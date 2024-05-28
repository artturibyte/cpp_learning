
#include <string>
#include <vector>
#include <cstdlib>

#include "cell.h"

class grid
{
    cell cells[rowmax+2][colmax+2];
public:
    // create cell at row, col
    void create(int row, int col);

    //Draw all cells
    void draw();

    //Populate random cells
    void randomize();

    //will cell survive at pos
    bool will_survive(int row, int col);

    //will cell born at pos
    bool will_create(int row, int col);

    void update(const grid& next);
};

//calc which cells survive and which are born
void calculate(grid& old_gen, grid& next_gen);

