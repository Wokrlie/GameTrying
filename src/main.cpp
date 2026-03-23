#include <iostream>
#include <raylib.h>

struct Properties {
    int window_default_width;
    int window_default_height;
    const char* window_title;
};

struct Status {};

void Update(Status* status) {}
void Draw(Status* status) {}

int main() {
    Properties properties;
    properties.window_default_width = 1280;
    properties.window_default_height = 720;
    properties.window_title = "Game";

    Status status;
    
    InitWindow(properties.window_default_width, properties.window_default_height, properties.window_title);
    while (!WindowShouldClose()) {
        Update(&status);
        BeginDrawing();
        Draw(&status);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}