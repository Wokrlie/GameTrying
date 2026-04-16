#pragma once
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

const std::string CURRENT_PATH = std::string(PROJECT_ROOT);

struct Properties {
    int window_default_width;
    int window_default_height;
    const char* window_title;

    std::vector<Color> background_colors;

    int player_speed;
};

struct Status
{
    Color current_background_color = GRAY;
};