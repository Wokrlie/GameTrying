#pragma once

class Timer {
    public:
        Timer(float cooldown = 0.0f);

        void UpdateTimer();
        void ResetTimer();
        bool ItsTimeToDo();

    private:
        float m_duration;
        float m_remaining;
};