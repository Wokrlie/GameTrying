#pragma once
#include <raylib.h>
#include <string>

#include "settings.h"

class Player {
    public:
        Player(Vector2 pos={0, 0},
            int speed=5, 
            std::string texture_path = std::string("")
        );
        ~Player();

        void Update(float dt);
        void Draw();

        void IsCollision(Direction direction, Shape object_shape);

        Rectangle GetRect();

    private:
        void InitResource(); // This function will call the other resource manage function.
        void load_resource();
        
    private:
        Vector2 m_pos;
        int m_speed;
        
        Texture2D m_texture;
        std::string m_texture_path;

        bool m_is_collision;
        Direction m_collision_direction;
        Shape m_collision_target_shape;
};