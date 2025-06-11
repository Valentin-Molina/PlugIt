#include "shared_library.hpp"

namespace plugin {

SharedLibrary::SharedLibrary(const std::string &library_name) {
  library_handle_ = dlopen(library_name.c_str(), RTLD_LAZY);
  if (!library_handle_) {
    throw std::runtime_error("Unable to load library " + library_name + ": " +
                             dlerror());
  }
}

SharedLibrary::~SharedLibrary() {
  if (library_handle_) {
    dlclose(library_handle_);
  }
}

} // namespace plugin