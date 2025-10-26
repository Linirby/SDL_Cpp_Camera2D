# Basic C++ Template for SDL2
This template has a Game and a GameTimer Class also has a sdl_init.hpp/.cpp files to initialize sdl in the main before running the Game
### Template classes!
**1. Class Game**
  - handle_event
  - update (with fixed delta time)
  - render (with interpolation setup, alpha)

**2. Class GameTimer**
  - get the fixed_delta
  - get the alpha
  - set a frame limiter
# 
### Compile It!
At the root you can file a **Makefile**
- To **build** the project run `make` or `make all`
- To **clean** the last compilation run `make clean`
- To **rebuild** `make rebuild`
