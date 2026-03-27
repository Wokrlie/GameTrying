#pragma once
#include <memory>

#include "player.h"
#include "timer.h"
#include "settings.h"

class Instance {
    public:
        Instance();
        void Init(Properties* properties);

        Timer* GetTimer();
        Player* GetPlayer();
    private:
        std::unique_ptr<Timer> m_timer;
        std::unique_ptr<Player> m_player;
};