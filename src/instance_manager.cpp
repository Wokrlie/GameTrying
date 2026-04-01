#include "instance_manager.h"

Instance::Instance() {}

void Instance::Init(Properties* properties) {
    m_timer = std::make_unique<Timer>(1.0f);

    std::string player_image_path = CURRENT_PATH + "/assets/player.png";
    m_player = std::make_unique<Player>(
        Vector2{
            static_cast<int>(properties->window_default_width / 2),
            static_cast<int>(properties->window_default_height / 2)
        },
        properties->player_speed,
        player_image_path
    );

    m_ground = std::make_unique<Actor>(Vector2{100, 0}, Vector2{500, 40});
}

Timer* Instance::GetTimer() {
    return m_timer.get();
}

Player* Instance::GetPlayer() {
    return m_player.get();
}

Actor* Instance::GetGround() {
    return m_ground.get();
}