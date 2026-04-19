#pragma once
#include <functional>
#include <memory>

class Plugin {
    public:
        Plugin(std::function<Plugin*()> constructor); // We maybe add GUID generation logic to it.
        virtual void Update(float dt);
        virtual void Shutdown();

        /* The plugins should setup by `SetXXX` functions. For example,
         * ```cpp
         * Render_plug.SetShader(...); // We are not have it. 
         * ```
         */
    
    private:
        std::unique_ptr<Plugin> m_instance;
};