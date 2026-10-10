// SPDX-License-Identifier: MIT

#include "./display.hh"

#include <SDL3/SDL.h>

bool Core::Display::create(Display &dp) {
  SDL_SetHint(SDL_HINT_ANDROID_TRAP_BACK_BUTTON, "1");
  SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                      SDL_GL_CONTEXT_PROFILE_ES);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    return false;
  }

  dp.window =
      SDL_CreateWindow(dp.props.title, dp.props.width, dp.props.height,
                       SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);

  if (!dp.window) {
    return false;
  }

  dp.context = SDL_GL_CreateContext(dp.window);

  if (!dp.context) {
    return false;
  }

  SDL_GL_MakeCurrent(dp.window, dp.context);
  SDL_GL_SetSwapInterval(1);

  SDL_GetWindowSize(dp.window, &dp.props.width, &dp.props.height);

  SDL_GetWindowSizeInPixels(dp.window, &dp.props.width_px,
                            &dp.props.height_px);

  dp.props.aspect_ratio =
      static_cast<float>(dp.props.width) / dp.props.height;
  dp.props.scaling = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());

  return true;
}

void Core::Display::destroy(Display &dp) {
  SDL_GL_MakeCurrent(nullptr, nullptr);

  SDL_GL_DestroyContext(dp.context);
  SDL_DestroyWindow(dp.window);
  SDL_Quit();
}
