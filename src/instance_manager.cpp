#include "instance_manager.h"

#include "utils.h"

Instance::Instance() {}

void Instance::Init(Properties *properties) {
    m_timer = std::make_unique<Timer>(1.0f);

    m_world_def = std::make_unique<b2WorldDef>(b2DefaultWorldDef());
    m_world_id = b2CreateWorld(m_world_def.get());

    m_accumulator = std::make_unique<Accumulator>();

    std::string player_image_path = CURRENT_PATH + "/assets/player.png";
    m_player = std::make_unique<Player>(
        Vector2{properties->window_default_width / 2.0f, properties->window_default_height / 2.0f},
        properties->player_speed,
        player_image_path,
        m_world_id);

    m_ground = std::make_unique<Actor>(Vector2{450, 500}, Vector2{500, 40});
}

void Instance::Update(Status *status, Properties *properties) {
    float dt = GetFrameTime();
    if (dt > 0.25f) dt = 0.25f;

    m_accumulator->AddAccumulator(dt);

    while (m_accumulator->GetAccumulator() >= properties->time_step) {
        b2World_Step(m_world_id, properties->time_step, properties->sub_step_count);
        m_accumulator->MinusAccumulator(properties->time_step);
    }

    GetTimer()->Update(dt);
    GetPlayer()->Update(dt);

    GetGround()->Update(dt);

    if (GetTimer()->ItsTimeToDo()) {
        status->current_background_color = properties->background_colors[0];
        GetTimer()->Reset();
    }
}

void Instance::Draw(Status *status, Properties *properties) {
    ClearBackground(status->current_background_color);
    GetGround()->Draw();
    GetPlayer()->Draw();
}

Instance::~Instance() {
    if (B2_IS_NON_NULL(m_world_id)) {
        b2DestroyWorld(m_world_id);
        m_world_id = b2_nullWorldId;
    }
}