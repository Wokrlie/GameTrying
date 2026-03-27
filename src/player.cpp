#include "player.h"
#include "utils.h"

#include <raylib.h>

Player::Player(Vector2 pos, int speed, char* texture_path) : m_pos(pos), 
    m_speed(speed), 
    m_texture(Texture2D()) {
    LoadTextureFromPNG(texture_path, &m_texture);
}

void Player::Update() {
    if(IsKeyDown(KEY_W)) m_pos.y -= 1 * m_speed;
    if(IsKeyDown(KEY_S)) m_pos.y += 1 * m_speed;
    if(IsKeyDown(KEY_A)) m_pos.x -= 1 * m_speed;
    if(IsKeyDown(KEY_D)) m_pos.x += 1 * m_speed;
}

void Player::Draw() {
    DrawTexture(m_texture, m_pos.x, m_pos.y, WHITE);
}