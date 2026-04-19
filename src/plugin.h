#pragma once

class Plugin {
    public:
        virtual void Init();
        virtual void Update(float dt);
        virtual void Shutdown();

        /* The plugins should setup by `SetXXX` functions. For example,
         * ```cpp
         * Render_plug.SetShader(...); // We are not have it. 
         * ```
         */
}