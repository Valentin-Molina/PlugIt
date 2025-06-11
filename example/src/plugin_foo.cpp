#include "plugin_foo.hpp"

#include <iostream>

namespace plugin::example {

void PluginFoo::run() { std::cout << "Plugin foo runnning" << std::endl; }

} // namespace plugin::example
