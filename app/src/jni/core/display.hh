// SPDX-License-Identifier: MIT

#pragma once

#include <SDL3/SDL.h>

namespace Core {
  struct Display {
    SDL_Window   *window  = nullptr;
    SDL_GLContext context = nullptr;

    struct {
      const char *title = "";

      int   width        = 0;
      int   height       = 0;
      int   width_px     = 0;
      int   height_px    = 0;
      float aspect_ratio = 0.0f;
      float scaling      = 0.0f;
    } config;

    bool create(void);
    ~Display(void);
  };
} // namespace Core
