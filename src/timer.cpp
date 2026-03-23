#include "timer.h"

#include <raylib.h>

Timer::Timer() {
    this->cooldown = 0.0f;
    this->will_be_checked_cooldown = 0.0f;
}

Timer::Timer(float cooldown) {
    this->cooldown = cooldown;
    this->will_be_checked_cooldown = cooldown;
}

bool Timer::ItsTimeToDo() {
    return will_be_checked_cooldown <= 0;
}

Timer *Timer::operator&() {
    return &Timer(this->cooldown);
}

void Timer::UpdateTimer() {
    this->will_be_checked_cooldown -= GetFrameTime();
}

void Timer::ResetTimer() {
    this->will_be_checked_cooldown = cooldown;
}