#ifndef CONSTANTS_H
#define CONSTANTS_H

struct constants
{
    static constexpr int window_height{544};
    static constexpr int window_width{1152};

    static constexpr int paddle_height{20};
    static constexpr int paddle_speed{5};

    static constexpr float ball_speed{2.0f};

    static constexpr int brick_height{20};
    static constexpr int brick_width{42};
    static constexpr int brick_offset{brick_width/2};
    static constexpr int brick_colums{24};
    static constexpr int brick_rows{3};
};


#endif  // CONSTANTS_H