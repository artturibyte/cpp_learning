#include    "interactions.hpp"

bool is_interacting(const Entity& e1, const Entity& e2) {
    auto box1 = e1.get_bounding_box();
    auto box2 = e2.get_bounding_box();
    return box1.intersects(box2);
}

// resolve collisions with paddle & ball
void handle_collision(Ball& b, const Paddle& p) {
    if (is_interacting(p, b)) {
        b.move_up();

        // make new direction depend on where the ball hits the paddle.
        // If left go left, if right go right

        if (b.x() < p.x())
            b.move_left();
        else
            b.move_right();
    }
};

void handle_collision(Ball& bl, Brick& br) {
    if (is_interacting(bl, br)) {
        // Destroy the brick in collision
        br.destroy();

        float left_overlap = bl.right() - br.left();
        float right_overlap =  br.left() - bl.right();
        float top_overlap =  bl.bottom() - br.top();
        float bottom_overlap =  br.bottom() - bl.top();

        bool from_left = std::abs(left_overlap) < std::abs(right_overlap);
        bool from_top = std::abs(top_overlap) < std::abs(bottom_overlap);

        bool min_x_overlap = from_left ? left_overlap : right_overlap;
        bool min_y_overlap = from_top ? top_overlap : bottom_overlap;

        if (std::abs(min_x_overlap) < std::abs(min_y_overlap)) {
            if (from_left)
                bl.move_left();
            else
                bl.move_right();
        }
        else {
            if (from_top)
                bl.move_up();
            else
                bl.move_down();
        }
    }
}