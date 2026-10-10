// SPDX-License-Identifier: MIT

#include "../core/display.hh"

#include <GLES3/gl32.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char **argv) {
  Core::Display dp = {};
  dp.props.title   = "GLES Template";
  dp.props.width   = 800;
  dp.props.height  = 600;

  if (!Core::Display::create(dp)) {
    Core::Display::destroy(dp);
    return 1;
  }

  glViewport(0, 0, dp.props.width_px, dp.props.height_px);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  bool is_running = true;
  while (is_running) {
    SDL_Event events = {};

    while (SDL_PollEvent(&events)) {
      switch (events.type) {
        case SDL_EVENT_QUIT:
          is_running = false;

          break;
      }
    }
    glClear(GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(dp.window);
  }

  Core::Display::destroy(dp);
  return 0;
}
