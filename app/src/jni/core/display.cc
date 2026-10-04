// SPDX-License-Identifier: MIT

#include "./display.hh"

#include <SDL3/SDL.h>

bool Core::Display::create(void) {
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

  window = SDL_CreateWindow(props.title, props.width, props.height,
                            SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);

  if (!window) {
    return false;
  }

  context = SDL_GL_CreateContext(window);

  if (!context) {
    return false;
  }

  SDL_GL_MakeCurrent(window, context);
  SDL_GL_SetSwapInterval(1);

  SDL_GetWindowSize(window, &props.width, &props.height);

  SDL_GetWindowSizeInPixels(window, &props.width_px, &props.height_px);

  props.aspect_ratio = static_cast<float>(props.width) / props.height;
  props.scaling      = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());

  return true;
}

void Core::Display::destroy(void) {
  SDL_GL_MakeCurrent(nullptr, nullptr);

  SDL_GL_DestroyContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
