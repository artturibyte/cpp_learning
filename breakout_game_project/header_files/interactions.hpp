#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include    "ball.hpp"
#include    "paddle.hpp"
#include    "brick.hpp"

// Determine wheter two entities overlap
bool is_interacting(const Entity& e1, const Entity& e2);

// Resolve collision between paddle and ball
void handle_collision(Ball& b, const Paddle& p);
void handle_collision(Ball& bl, Brick& br);

#endif