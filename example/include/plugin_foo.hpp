#pragma once

#include "example_plugin.hpp"

namespace plugin::example {

class PluginFoo : public ExamplePlugin {
public:
  void run() final;
};

} // namespace plugin::example