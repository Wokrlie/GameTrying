#include "collision.h"

void CollisionBox_plug::Init(b2Vec2 pos, b2Vec2 size, b2WorldId world_id) {
        b2BodyDef body_def = b2DefaultBodyDef();
        body_def.position = pos;
        m_body_id = b2CreateBody(world_id, &body_def);
}

void CollisionBox_plug::Update() {}