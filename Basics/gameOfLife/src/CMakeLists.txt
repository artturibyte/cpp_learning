add_executable(game_of_life main.cpp)

add_library(game_of_life cell.cpp)
add_library(game_of_life grid.cpp)