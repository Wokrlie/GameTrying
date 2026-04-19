#pragma once

class Plugin {
    public:
        virtual void Init();
        virtual void Update(float dt);
        virtual void Shutdown();
}