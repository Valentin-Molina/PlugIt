#include "shared_library.hpp"

#include <gtest/gtest.h>

TEST(SharedLibrary, CanLoadExampleLibrary) {
  plugin::SharedLibrary library("libplugit_example.so");
}

TEST(SharedLibrary, LibraryLoadingThrowsIfMisspelled) {
  ASSERT_THROW(plugin::SharedLibrary library("libplugit_expl.so"),
               std::runtime_error);
}

TEST(SharedLibrary, CanLoadExistingFunction) {
  plugin::SharedLibrary library("libplugit_example.so");
  const auto function = library.loadFunction<void()>("sayHello");
  ASSERT_TRUE(function != nullptr);
}

TEST(SharedLibrary, FunctionLoadingThrowsIfMisspelled) {
  plugin::SharedLibrary library("libplugit_example.so");
  ASSERT_THROW(library.loadFunction<void()>("say_hello"), std::runtime_error);
}