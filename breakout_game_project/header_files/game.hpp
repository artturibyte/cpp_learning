#ifndef GAME_H
#define GAME_H

#include    <memory>
#include    <typeinfo>

#include    "constants.hpp"
#include    "background.hpp"
#include    "ball.hpp"
#include    "paddle.hpp"
#include    "brick.hpp"

enum class game_state{paused, running, game_over, game_won};

// Use aliases to simplify the code
using entity_vector = std::vector<std::unique_ptr<Entity>>;
using entity_alias_vector = std::vector<Entity *>;

// Instead of having all entities on game class, we create entity manager.
class EntityManager {
	// A vector to store all the entities in the game (all brick objects, background, ball, paddle)
	entity_vector all_entities;

	// A map to store the entities grouped by type
	// We can iterate over this to get a vector of all brick objects, then a vector of all ball objects, etc
	// The vector will contain non-owning pointers to the objects
	// Do not delete these pointers!
	// Do not use them after the objects they point to have been destroyed!
	std::map<size_t, entity_alias_vector> grouped_entities;

    public:
    // Function to create entity object of type T, using Args as entitys constructor arguments.
    // Using variadic template to use any number of arguments
    // We use perfect forwarding to avoid copying
    template <typename T, typename... Args>
    T& create(Args&&... args) {
        // Check that the parameter is derived from the entity class
        static_assert(std::is_base_of<Entity, T>::value, 
        R"("T" type parameter in create must be derived from entity!")");

        // Make unique pointer of the entity.
        // Forwarding arguments to constructor
        auto ptr{std::make_unique<T>(std::forward<Args>(args)...)};

        // Create alias pointer of entity
        auto ptr_alias = ptr.get();

        // Get the hash code of the entitys object type
        auto hash = typeid(T).hash_code();

        // Insert alias pointer into the map
        grouped_entities[hash].emplace_back(std::move(ptr_alias));

        all_entities.emplace_back(std::move(ptr));

        return *ptr_alias;
    }

    // Scan and cleanup destroyed entities
    void refresh();

    // destroy all entities
    void clear();

	// Update all the entities
	void update();

	// Function to make all the entities draw themselves
	void draw(sf::RenderWindow& window);
    
    template <typename T>
    auto& get_all() {
        return grouped_entities[typeid(T).hash_code()];
    }

    // Apply function to all entities of type
    template <typename T, typename Func>
    void apply_all(const Func& func) {
        auto& entity_group{get_all<T>()};

        for (auto ptr : entity_group) {
            func(*dynamic_cast<T*>(ptr));
        }
    }

};

class Game {
    sf::RenderWindow game_window{{constants::window_width, constants::window_height}, "Shenzhen game"};
    
    EntityManager manager;

    game_state state{game_state::running};

    sf::Font sf_font;
    sf::Text text_state, text_lives;
    int lives{constants::lives};

    public:
        Game();
        // Reset game
        void reset();

        // Run game loop
        void run();    
};


#endif