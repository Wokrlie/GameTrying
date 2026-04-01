#pragma once
#include <raylib.h>

class Actor {
    public:
        Actor(Vector2 pos, Vector2 length);
        void Update();
        void Draw();

        Rectangle GetRect();
    private:
        Vector2 m_pos;
        Rectangle m_rect;
};