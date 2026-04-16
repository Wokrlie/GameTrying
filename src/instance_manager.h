#pragma once
#include <memory>

#include <box2d/box2d.h>

#include "player.h"
#include "timer.h"
#include "actor.h"
#include "settings.h"

class Instance {
    public:
        Instance();
        ~Instance();
        void Init(Properties* properties);
        void Update(Status *status, Properties *properties);
        void Draw(Status *status, Properties *properties);

        Timer* GetTimer() { return m_timer.get(); }
        Player* GetPlayer() { return m_player.get(); }
        Actor* GetGround() { return m_ground.get(); }
    private:
        std::unique_ptr<b2WorldDef> m_world_def;
        b2WorldId m_world_id;

        std::unique_ptr<Timer> m_timer;
        std::unique_ptr<Player> m_player;
        std::unique_ptr<Actor> m_ground;
};