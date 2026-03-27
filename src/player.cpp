#include "player.h"
#include "utils.h"

#include <raylib.h>
#include <string>
#include <stdexcept>

Player::Player(Vector2 pos, int speed, std::string texture_path) : 
    m_pos(pos), 
    m_speed(speed), 
    m_texture(Texture2D()),
    m_texture_path(texture_path)
    { InitResource(); }

void Player::Update() {
    if(IsKeyDown(KEY_W)) m_pos.y -= 1 * m_speed;
    if(IsKeyDown(KEY_S)) m_pos.y += 1 * m_speed;
    if(IsKeyDown(KEY_A)) m_pos.x -= 1 * m_speed;
    if(IsKeyDown(KEY_D)) m_pos.x += 1 * m_speed;
}

void Player::Draw() {
    DrawTexture(m_texture, m_pos.x, m_pos.y, WHITE);
}

void Player::InitResource() {
    load_resource();
}

void Player::load_resource() {
    LoadTextureFromPNG(m_texture_path, &m_texture);
}