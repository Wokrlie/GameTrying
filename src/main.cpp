#include <iostream>
#include <raylib.h>

#include "settings.h"
#include "instance_manager.h"

struct Status {
    Color current_background_color;
};

void Init(Properties* properties, Instance* instance_manager) {
    properties->window_default_width = 1280;
    properties->window_default_height = 720;
    properties->window_title = "Game";

    InitWindow(
        properties->window_default_width, 
        properties->window_default_height, 
        properties->window_title
    );

    properties->background_colors = {GRAY, GREEN, RED, BLUE, YELLOW};

    properties->player_speed = 5;

    instance_manager->Init(properties);
}

// IMPORTANT: The Update function shoudn't change the properties
void Update(Status* status, Instance* instances, Properties* properties) {
    instances->GetTimer()->Update();
    instances->GetPlayer()->Update();

    if (instances->GetTimer()->ItsTimeToDo()) {
        status->current_background_color = properties->background_colors[0];
        instances->GetTimer()->Reset();
    }

}

void Draw(Status* status, Instance* instances) {
    ClearBackground(status->current_background_color);
    instances->GetPlayer()->Draw();
}

int main() {
    Properties properties;
    Status status;
    Instance instances;

    Init(&properties, &instances);

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