
#include "life.hh"
#include <iostream>

class cell {
    bool alive;

    public:
        //Constructor
        //Cells are empty by default
        cell(): alive(false) {}

        void draw(int row, int col) const;

        void create() {
            alive = true;
        }

        void erase() {
            alive = false;
        }

        bool is_alive() const { return alive; }

};

