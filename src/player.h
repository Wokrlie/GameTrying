#pragma once
#include <raylib.h>

class Player {
    public:
        Player(Vector2 pos={0, 0}, int speed=5, char* texture_path = (char*)"");

        void Update();
        void Draw();

    private:
        Vector2 m_pos;
        Texture2D m_texture;
        int m_speed;
};