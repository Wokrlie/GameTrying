#pragma once
#include <vector>
#include <memory>

#include <raylib.h>
#include <box2d/box2d.h>

#include "plugin.h"

class Actor {
    public:
        Actor(Vector2 pos, Vector2 size);
        void Init();
        virtual void Update(float dt);
        virtual void Draw();
        void Shutdown();

        virtual Rectangle GetRect();

        void AddNewPlugin(std::unique_ptr<Plugin> p);

    private:
        b2BodyDef m_body_def;
        b2BodyId m_body_id;

        std::vector<Plugin> m_plugins;

    protected:
        Rectangle m_rect;
        Vector2 m_pos;
};