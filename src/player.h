#pragma once
#include <raylib.h>

class Player {
    public:
        Player(Vector2 pos={0, 0}, int speed=5);

        void Update();
        void Draw();

    private:
        Vector2 m_pos;
        int m_speed;
};