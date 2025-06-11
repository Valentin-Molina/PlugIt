#include "plugin_bar.hpp"

#include <iostream>

namespace plugin::example {

void PluginBar::run() { std::cout << "PluginBar running..." << std::endl; }

} // namespace plugin::example

void sayHello(void) { std::cout << "Hello" << std::endl; }
