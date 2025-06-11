#pragma once

#include "example_plugin.hpp"

namespace plugin::example {

class PluginBar : public ExamplePlugin {
public:
  void run() final;
};

} // namespace plugin::example

extern "C" {
void sayHello(void);
}