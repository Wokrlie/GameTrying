#include "player.h"
#include "utils.h"
#include "settings.h"

#include <raylib.h>
#include <string>
#include <stdexcept>

Player::Player(Vector2 pos, int speed, std::string texture_path) : 
    m_pos(pos), 
    m_speed(speed), 
    m_texture(Texture2D()),
    m_texture_path(texture_path),
    m_collision_direction(Direction::None)
    { InitResource(); }

Player::~Player() {
    UnloadTexture(m_texture);
}

void Player::Update(float dt) {
    TraceLog(LOG_INFO, "The collision direction: %d", (int)m_collision_direction);
    if(IsKeyDown(KEY_W) && m_collision_direction != Direction::Up ) m_pos.y -= 1 * m_speed * dt;
    if(IsKeyDown(KEY_S) && m_collision_direction != Direction::Down) m_pos.y += 1 * m_speed * dt;
    if(IsKeyDown(KEY_A) && m_collision_direction != Direction::Left) m_pos.x -= 1 * m_speed * dt;
    if(IsKeyDown(KEY_D) && m_collision_direction != Direction::Right) m_pos.x += 1 * m_speed * dt;
}

void Player::Draw() {
    Rectangle sourceRec = { 0.0f, 0.0f, (float)m_texture.width, (float)m_texture.height };
    Rectangle destRec = { m_pos.x, m_pos.y, m_texture.width/2.0f, m_texture.height/2.0f };
    Vector2 origin = { (float)m_texture.width, (float)m_texture.height }; // Center point
    
    DrawTexturePro(m_texture, sourceRec, destRec, origin, 0.0f, WHITE);
}

void Player::InitResource() {
    load_resource();
}

void Player::load_resource() {
    LoadTextureFromPNG(m_texture_path, &m_texture);
}

Rectangle Player::GetRect() {
    return { m_pos.x, m_pos.y, m_texture.width/2.0f, m_texture.height/2.0f };
}