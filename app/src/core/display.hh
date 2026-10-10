// SPDX-License-Identifier: MIT

#pragma once

#include <SDL3/SDL.h>

namespace Core {
  struct Display {
    SDL_Window   *window;
    SDL_GLContext context;

    struct {
      const char *title;

      int   width;
      int   height;
      int   width_px;
      int   height_px;
      float aspect_ratio;
      float scaling;
    } props;

    static bool create(Display &dp);
    static void destroy(Display &dp);
  };
} // namespace Core
