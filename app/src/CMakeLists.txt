project("main")

find_library("android" "android")
find_library("egl" "EGL")
find_library("gles" "GLESv3")
find_library("log" "log")

add_library("main" SHARED
  "platform/main.cc"
  "core/display.cc"

  "core/display.hh"
)

set_target_properties("main" PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN TRUE
)

target_compile_options("main" PRIVATE
  "-fno-rtti"
  "-fno-exceptions"
)

target_include_directories("main" PRIVATE
  "${CMAKE_SOURCE_DIR}/third_party/include"
)

target_link_libraries("main" PRIVATE
  "${android}"
  "${egl}"
  "${gles}"
  "${log}"

  SDL3::SDL3
)
