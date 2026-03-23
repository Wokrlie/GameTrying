#pragma once

class Timer {
    public:
        Timer(float cooldown = 0.0f);

        void Update();
        void Reset();
        bool ItsTimeToDo();

    private:
        float m_duration;
        float m_remaining;
};