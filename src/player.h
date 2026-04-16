#pragma once
#include <raylib.h>
#include <box2d/box2d.h>
#include <string>

#include "settings.h"
#include "actor.h"

class Player : public Actor {
    public:
        Player(Vector2 pos,
            int speed,
            std::string texture_path,
            b2WorldId world_id
        );
         Player() = delete;
        ~Player();

        void Update(float dt) override;
        void Draw() override;

        Rectangle GetRect();

    private:
        void InitResource() override; // This function will call the other resource manage function.
        void InitPhysics(Vector2 pos, b2WorldId world_id) override;
        
    private:
        int m_speed;
        
        Texture2D m_texture;
        std::string m_texture_path;

        b2BodyDef m_body_def;
        b2BodyId m_body_id;
};