#pragma once
#include <raylib.h>
#include <string>

class Player {
    public:
        Player(Vector2 pos={0, 0},
            int speed=5, 
            std::string texture_path = std::string("")
        );

        void Update();
        void Draw();

    private:
        void InitResource(); // This function will call the other resource manage function.
        void load_resource();
    private:
        Vector2 m_pos;
        int m_speed;
        
        Texture2D m_texture;
        std::string m_texture_path;
};