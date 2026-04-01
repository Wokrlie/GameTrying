#pragma once
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

const std::string CURRENT_PATH = std::string(PROJECT_ROOT);

enum Direction {
    Up = 0,
    Down,
    Left,
    Right,
    None
};

enum Shape { 
    Rect = 0,
    Circ
};

struct Properties {
    int window_default_width;
    int window_default_height;
    const char* window_title;

    std::vector<Color> background_colors;

    int player_speed;
};