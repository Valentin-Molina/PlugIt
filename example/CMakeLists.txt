include_directories(include)

add_library(${PROJECT_NAME}_example SHARED src/plugin_foo.cpp src/plugin_bar.cpp)