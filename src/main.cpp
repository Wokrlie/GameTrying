#include <iostream>
#include <raylib.h>
#include <vector>

#include "timer.h"
#include "player.h"

struct Instance {
    Timer timer;
    Player player;
};

struct Properties {
    int window_default_width;
    int window_default_height;
    const char* window_title;

    std::vector<Color> background_colors;

    int player_speed;
};

struct Status {
    Color current_background_color;
};

void Init(Properties* properties, Instance* instances) {
    properties->window_default_width = 1280;
    properties->window_default_height = 720;
    properties->window_title = "Game";

    properties->background_colors = {GRAY, GREEN, RED, BLUE, YELLOW};

    properties->player_speed = 5;

     instances->timer = Timer(1.0f);
    instances->player = Player(
        {
            static_cast<int>(properties->window_default_width / 2),
            static_cast<int>(properties->window_default_height / 2)
        },
        properties->player_speed,
        (char*)"../assets/player.png"
    );
    
    InitWindow(
        properties->window_default_width, 
        properties->window_default_height, 
        properties->window_title
    );
}

// IMPORTANT: The Update function shoudn't change the properties
void Update(Status* status, Instance* instances, Properties* properties) {
    instances->timer.Update();
    instances->player.Update();

    if (!instances->timer.ItsTimeToDo()) {
        return;
    }
    status->current_background_color = properties->background_colors[0];
    
    instances->timer.Reset();

}

void Draw(Status* status, Instance* instances) {
    ClearBackground(status->current_background_color);
    instances->player.Draw();
}

int main() {
    Properties properties;
    Status status;
    Instance instances;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        Update(&status, &instances, &properties);

        BeginDrawing();
        Draw(&status, &instances);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}