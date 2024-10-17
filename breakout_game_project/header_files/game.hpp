#ifndef GAME_H
#define GAME_H

#include    "constants.hpp"
#include    "background.hpp"
#include    "ball.hpp"
#include    "paddle.hpp"
#include    "brick.hpp"

enum class game_state{paused, running};

class Game {
    sf::RenderWindow game_window{{constants::window_width, constants::window_height}, "Shenzhen game"};
    
    background bg{0, 0};
    Ball ball{constants::window_width/2, constants::window_height/2 + 20};
    Paddle paddle{0, constants::window_height};

    std::vector<Brick>  brick_vec;
    

    game_state state{game_state::running};

    public:
        Game();

        // Reset game
        void reset();

        // Run game loop
        void run();
    
};


#endif