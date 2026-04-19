#include "actor.h"

Actor::Actor(Vector2 pos, Vector2 size) :m_pos(pos), m_rect({pos.x, pos.y, size.x, size.y}) { Init(); }

void Actor::Init() {}

void Actor::AddNewPlugin(std::unique_ptr<Plugin> p) {
    m_plugins.push_back(std::move(p));
}

void Actor::Update(float dt) {
    for ( auto& plugin : m_plugins ) {
        plugin->Update(dt);
    }
}

void Actor::Draw() {
    DrawRectangle(m_pos.x, m_pos.y, m_rect.width, m_rect.height, GREEN);
}

void Actor::Shutdown() {
    for ( auto& plugin : m_plugins ) {
        plugin->Shutdown();
    }
}

Rectangle Actor::GetRect() { return m_rect; }
