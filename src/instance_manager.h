#pragma once
#include <memory>

#include "player.h"
#include "timer.h"
#include "actor.h"
#include "settings.h"

class Instance {
    public:
        Instance();
        void Init(Properties* properties);

        Timer* GetTimer();
        Player* GetPlayer();
        Actor* GetGround();
    private:
        std::unique_ptr<Timer> m_timer;
        std::unique_ptr<Player> m_player;
        std::unique_ptr<Actor> m_ground;
};