# PlugIt

PlugIt is an exploratory side aimed at learning about about **shared libray loading**, **class loading** and **plugin systems** in C++.

[![PlugIt CI](https://github.com/Valentin-Molina/PlugIt/actions/workflows/github-actions.yml/badge.svg?branch=main)](https://github.com/Valentin-Molina/PlugIt/actions/workflows/github-actions.yml)

[![codecov](https://codecov.io/gh/Valentin-Molina/PlugIt/branch/main/graph/badge.svg)](https://codecov.io/gh/Valentin-Molina/PlugIt)

## ToDo:

- [ ] Project set-up and CI
  - [x] cmake
  - [x] Testing
  - [ ] Ci and coverage with clang
  - [x] clangd
  - [ ] clangformat
  - [ ] clang-tidy
- [x] Load a shared library 
- [ ] Load a class with a simple constructor (no arguments)
- [ ] Load a class with a complex constructor
- [ ] Define a plugin from its interface
- [ ] Load a plugin via the interface

## Compile on Linux

1. Install requirements:

```sh
sudo apt install cmake clang
```

2. Configure using the desired preset (e.g. clang-debug):

```sh
cmake --preset clang-debug
```

3. Build with the corresponding build preset (e.g. build-clang-debug):

```sh
cmake --build --preset build-clang-debug
```

## Develop on Linux

### Clangd setup

The clangd language could be used directly after an initial build with clang (e.g. clang-debug).
The build will automatically generate the required ``compile_commands.json`` at the project root (symlink).

### Test

Test could be run after a debug build using the corresponding preset:

```sh
ctest --preset test-clang-debug
```