#include    "game.hpp"
#include    "interactions.hpp"


// Function to scan all entities and clean up the destroyed ones
void EntityManager::refresh() {
	// We must clean up the alias pointers first, to avoid dangling pointers
	// We simply remove them from their vector
	for (auto& [type, alias_vector] : grouped_entities) {
		// remove_if takes an iterator range and a predicate
		// All the elements for which the predicate is true are moved to the back
		// It returns an iterator to the first moved element
		// erase takes an iterator range and deletes all the elements in the range
		alias_vector.erase(remove_if(begin(alias_vector), end(alias_vector),
				[](const auto& p) { return p->is_destroyed(); }
				),
		end(alias_vector));
	}

	// Now we can safely destroy the objects, now that there are no aliases to them
	all_entities.erase(remove_if(begin(all_entities), end(all_entities),
			[](const auto& p) { return p->is_destroyed(); }
			),
	end(all_entities));
}

// Function to destroy all entities
void EntityManager::clear() {
	// Again, we must clean up the alias pointers first
	grouped_entities.clear();
	all_entities.clear();
}

// Function to update all the entities
void EntityManager::update() {
	for (auto& e : all_entities)
	e->update();
}

// Function to update make all the entities draw themselves
void EntityManager::draw(sf::RenderWindow& window) {
	for (auto& e : all_entities)
	e->draw(window);
}


Game::Game() {
    reset();
    game_window.setFramerateLimit(60);

	sf_font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf");
	text_state.setFont(sf_font);
	text_state.setCharacterSize(55);
	text_state.setFillColor(sf::Color::Yellow);
	text_state.setPosition(constants::window_width/2 - 50,constants::window_height/2);
	//text_state.setString("Paused");

	text_lives.setFont(sf_font);
	text_lives.setCharacterSize(35);
	text_lives.setFillColor(sf::Color::Black);
	text_lives.setPosition(0, 0);
	text_lives.setString("Lives:" + std::to_string(lives));
};

void Game::reset() {
	lives = constants::lives;
    state = game_state::paused;

	// Destroy all the entities and re-create them
	manager.clear();

    manager.create<background>(0, 0);
	// Create ball above paddle
    manager.create<Ball>(constants::window_width/2, constants::window_height - 50);
    manager.create<Paddle>(constants::window_width/2, constants::window_height);

    // Init brick vector
    	for (int i = 0; i < constants::brick_columns; ++i) {
		for (int j = 0; j < constants:: brick_rows; ++j) {
			// Calculate the brick's position
			float x = constants::brick_offset + (i + 1) * constants::brick_width;
			float y = (j + 1) * constants::brick_height;

			// Create the brick object
			manager.create<Brick>(x, y);
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
			// Calculate the updated graphics
			manager.update();

			// For every ball, call a function which
			//    For every brick, call a function which
			//         Calls handle_collision with the ball and the brick as arguments
			manager.apply_all<Ball>([this](auto& the_ball) {
				manager.apply_all<Brick>([&the_ball](auto& the_brick) {
					handle_collision(the_ball, the_brick);
				});
			});

			// Paddle interaction
			manager.apply_all<Ball>([this](auto& the_ball) {
				manager.apply_all<Paddle>([&the_ball](auto& the_paddle) {
					handle_collision(the_ball, the_paddle);
				});
			});
			manager.refresh();
        }

		// Display the updated graphics
		manager.draw(game_window);
		

		if (state != game_state::running) {
			switch (state)
			{
			case game_state::paused:
				text_state.setString("PAUSED");
				break;
			
			case game_state::game_over:
				text_state.setString("Game over!");
				break;
			
			case game_state::game_won:
				text_state.setString("Game won!!");
				break;
			
			default:
				break;
			}
			game_window.draw(text_state);
		}
		else {
			if (manager.get_all<Ball>().empty()) {
				manager.create<Ball>(constants::window_width/2, constants::window_height/2);
				lives--;
			}
			
			// player wons
			if (manager.get_all<Brick>().empty())
				state = game_state::game_won;
			
			if (lives <= 0)
				state = game_state::game_over;
			// Update game lives
			text_lives.setString("Lives:" + std::to_string(lives));
		game_window.draw(text_lives);    
    	}
		
	game_window.display();
	}
}