#pragma once
#include <box2d/box2d.h>

#include "../plugin.h"

class CollisionBox_plug : Plugin {
    public:
        void Init(b2Vec2 pos, b2Vec2 size, b2WorldId world_id);
        void Shutdown() override;

    private:
        b2BodyId m_body_id;
};