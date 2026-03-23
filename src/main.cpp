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
};

struct Status {
    Color current_background_color;
};

// IMPORTANT: The Update function shoudn't change the properties
void Update(Status* status, Instance* instances, Properties* properties) {
    instances->timer.Update();
    instances->player.Update();

    if (!instances->timer.ItsTimeToDo()) {
        return;
    }
    status->current_background_color = properties->
        background_colors.data()[GetRandomValue(0, properties->background_colors.size())];
    
    instances->timer.Reset();

}

void Draw(Status* status, Instance* instances) {
    ClearBackground(status->current_background_color);
    instances->player.Draw();
}

int main() {
    Properties properties;
    properties.window_default_width = 1280;
    properties.window_default_height = 720;
    properties.window_title = "Game";

    properties.background_colors = {RAYWHITE, WHITE, GRAY, GREEN, RED, BLUE, YELLOW};

    Status status;
    Instance instances;

    instances.timer = Timer(1.0f);
    
    InitWindow(properties.window_default_width, properties.window_default_height, properties.window_title);

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