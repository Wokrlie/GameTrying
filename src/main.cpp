#include <iostream>
#include <raylib.h>

#include "settings.h"
#include "utils.h"
#include "instance_manager.h"

void Init(Properties *properties)
{
    properties->window_default_width = 1280;
    properties->window_default_height = 720;
    properties->window_title = "Game";

    InitWindow(
        properties->window_default_width,
        properties->window_default_height,
        properties->window_title);

    properties->background_colors = {GRAY, GREEN, RED, BLUE, YELLOW};

    properties->player_speed = 500;
}

// IMPORTANT: The Update function shoudn't change the properties
void Update(Status *status, Instance *instances, Properties *properties)
{
    instances->Update(status, properties);
}

void Draw(Status *status, Instance *instances, Properties* properties)
{
    instances->Draw(status, properties);
}

int main()
{
    Properties properties;
    Status status;

     Init(&properties); // We don't init instances manager here because it need an independent life cycle

    SetTargetFPS(60);
    {
        Instance instances;
        instances.Init(&properties);

        while (!WindowShouldClose())
        {
            Update(&status, &instances, &properties);
            BeginDrawing();
            Draw(&status, &instances, &properties);
            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}