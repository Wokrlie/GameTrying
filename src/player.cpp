#include "player.h"

#include <raylib.h>

Player::Player(Vector2 pos, int speed) : m_pos(pos), m_speed(speed) {}

void Player::Update() {
    if(IsKeyDown(KEY_W)) m_pos.y -= 1 * m_speed;
    if(IsKeyDown(KEY_S)) m_pos.y += 1 * m_speed;
    if(IsKeyDown(KEY_A)) m_pos.x -= 1 * m_speed;
    if(IsKeyDown(KEY_D)) m_pos.x += 1 * m_speed;
}

void Player::Draw() {
    DrawRectangle(m_pos.x, m_pos.y, 64, 64, GREEN);
}