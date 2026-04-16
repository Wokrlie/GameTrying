#pragma once
#include <raylib.h>
#include <box2d/box2d.h>

class Actor {
    public:
        Actor(Vector2 pos, Vector2 size);
        virtual void Update(float dt);
        virtual void Draw();

        virtual Rectangle GetRect();

    private:
        virtual void InitResource() {};
        virtual void InitPhysics(Vector2 pos, b2WorldId world_id) {
             m_body_def = b2DefaultBodyDef();
            m_body_def.position = { pos.x, pos.y }; // Different type, raylib Vector2 and box2d vec
            m_body_id = b2CreateBody(world_id, &m_body_def);
        };
    private:
        b2BodyDef m_body_def;
        b2BodyId m_body_id;

    protected:
        Rectangle m_rect;
        Vector2 m_pos;
};