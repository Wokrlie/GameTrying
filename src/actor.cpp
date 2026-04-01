#include "actor.h"

Actor::Actor(Vector2 pos, Vector2 length) :m_pos(pos), m_rect({pos.x, pos.y, length.x, length.y}) {}

Rectangle Actor::GetRect() { return m_rect; }

void Actor::Update() {}
void Actor::Draw() {
    DrawRectangle(m_pos.x, m_pos.y, m_rect.width, m_rect.height, GREEN);
}