#include    "game.hpp"
#include    "interactions.hpp"


Game::Game() {
    // Init brick vector
    reset();
    game_window.setFramerateLimit(60);
};

void Game::reset() {
    // Init brick vector
    for (size_t i = 0; i < constants::brick_colums; i++)
    {
        for (size_t j = 0; j < constants::brick_rows; j++)
        {
            // Calculatte brick position
            float x = constants::brick_width * (i + 1);
            float y = constants::brick_height * (j + 1);
            brick_vec.emplace_back(x, y);
        }
    }
}

void Game::run() {
    bool pause_key_active{false};
    while (game_window.isOpen())
    {
        game_window.clear(sf::Color::Black);

        sf::Event event;

        while (game_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game_window.close();

            if (event.type == sf::Event::Resized)
                // Force window size
                game_window.setSize(sf::Vector2u(constants::window_width, constants::window_height)); 
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            break;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            if (!pause_key_active) {
                if (state != game_state::paused)
                    state = game_state::paused;
                else
                    state = game_state::running;
            }
            pause_key_active = true;
        }
        else {
            pause_key_active = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            reset();

        // In paused state, dont update collisions.
        if (state != game_state::paused) {
            // Calculate directions
            ball.update();
            paddle.update();

            // Handle collisions
            handle_collision(ball, paddle);

            for (auto& b : brick_vec)
                handle_collision(ball, b);
        
            // Erase destroyed bricks
            brick_vec.erase(
                std::remove_if(begin(brick_vec), end(brick_vec), 
                    [](const Brick& b){ return b.is_destroyed();}), 
                end(brick_vec));
        }

        // Draw new frame
        bg.draw(game_window);
        ball.draw(game_window);
        paddle.draw(game_window);

        for (auto b : brick_vec)
            b.draw(game_window);

        game_window.display();   
    }
}