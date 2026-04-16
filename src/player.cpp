#include "player.h"
#include "utils.h"
#include "settings.h"

#include <raylib.h>
#include <string>
#include <stdexcept>

Player::Player(Vector2 pos, int speed, std::string texture_path, b2WorldId world_id) :
    Actor(pos, {1.0f, 1.0f}),  // Temp size.
    m_speed(speed), 
    m_texture(Texture2D()),
    m_texture_path(texture_path) {
        InitResource();
        InitPhysics(pos, world_id);
}

Player::~Player() {
    TraceLog(LOG_INFO, "Player destroyed");
    if (m_texture.id != 0) UnloadTexture(m_texture);
}

void Player::Update(float dt) {
    if(IsKeyDown(KEY_W)) m_pos.y -= 1 * m_speed * dt;
    if(IsKeyDown(KEY_S)) m_pos.y += 1 * m_speed * dt;
    if(IsKeyDown(KEY_A)) m_pos.x -= 1 * m_speed * dt;
    if(IsKeyDown(KEY_D)) m_pos.x += 1 * m_speed * dt;
}

void Player::Draw() {
    Rectangle sourceRec = { 0.0f, 0.0f, (float)m_texture.width, (float)m_texture.height };
    Rectangle destRec = { m_pos.x, m_pos.y, m_texture.width/2.0f, m_texture.height/2.0f };
    Vector2 origin = { (float)m_texture.width, (float)m_texture.height }; // Center point
    
    DrawTexturePro(m_texture, sourceRec, destRec, origin, 0.0f, WHITE);
}

void Player::InitResource() {
    LoadTextureFromPNG(m_texture_path, &m_texture);
}

void Player::InitPhysics(Vector2 pos, b2WorldId world_id) {
    m_body_def = b2DefaultBodyDef();
    m_body_def.position = { pos.x, pos.y }; // Different type, raylib Vector2 and box2d vec
    m_body_id = b2CreateBody(world_id, &m_body_def);
}

Rectangle Player::GetRect() {
    return { m_pos.x, m_pos.y, m_texture.width/2.0f, m_texture.height/2.0f };
}