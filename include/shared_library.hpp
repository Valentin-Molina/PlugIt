#pragma once

#include <dlfcn.h>
#include <functional>
#include <iostream>

namespace plugin {

class SharedLibrary {

public:
  SharedLibrary(const std::string &libray_name);
  ~SharedLibrary();

  template <typename Func>
  Func *loadFunction(const std::string &function_name) {
    dlerror();
    void *symbol = dlsym(library_handle_, function_name.c_str());
    const char *error = dlerror();
    if (error) {
      throw std::runtime_error("Unable to find function [" + function_name +
                               "]: " + error);
    }
    return reinterpret_cast<Func *>(symbol);
  }

private:
  void *library_handle_ = nullptr;
};

} // namespace plugin