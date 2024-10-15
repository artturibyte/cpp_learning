#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include    "ball.hpp"
#include    "paddle.hpp"
#include    "brick.hpp"

// Determine wheter two entities overlap
bool is_interacting(const entity& e1, const entity& e2);

// Resolve collision between paddle and ball
void handle_collision(ball& b, const paddle& p);
void handle_collision(ball& bl, brick& br);

#endif