#include "timer.h"

#include <raylib.h>

Timer::Timer(float duration) : m_duration(duration),
                               m_remaining(duration) {}

bool Timer::ItsTimeToDo() {
    return m_remaining <= 0;
}

void Timer::UpdateTimer() {
    this->m_remaining -= GetFrameTime();
}

void Timer::ResetTimer() {
    this->m_remaining = m_duration;
}