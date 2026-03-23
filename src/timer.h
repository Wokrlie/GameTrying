#pragma once

class Timer {
    public:
        Timer();
        Timer(float cooldown);

        void UpdateTimer();
        void ResetTimer();
        bool ItsTimeToDo();

        Timer* operator&();
    private:
        float cooldown;
        float will_be_checked_cooldown;
};