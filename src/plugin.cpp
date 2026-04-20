#include "plugin.h"

Plugin::Plugin(std::function<Plugin *()> constructor) : m_instance(constructor()) {}
void Plugin::Update(float dt) {}
void Plugin::Shutdown() {}
