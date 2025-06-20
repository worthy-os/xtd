cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.drawing.native.wxwidgets)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
if (MSVC)
  add_compile_options(/wd5054)
elseif (APPLE)
  set(XTD_EXTRA_LIBS "-framework Cocoa")
elseif (UNIX)
  find_package(PkgConfig)
  pkg_check_modules(GTK gtk+-3.0)
  add_include_directories(${GTK_INCLUDE_DIRS})
  add_reference_directories(${GTK_LIBRARY_DIRS})
  add_references(${GTK_LIBRARIES})
endif()

find_package(wxWidgets 3.2 REQUIRED)
include(${wxWidgets_USE_FILE})
#add_include_directories(${wxWidgets_INCLUDE_DIRS})
#add_reference_directories(${wxWidgets_LIBRARY_DIRS})
if (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "FreeBSD")
  add_references(-L${wxWidgets_LIBRARY_DIRS})
endif ()
add_references(${wxWidgets_LIBRARIES})

add_include_directories("include")
add_references(xtd.drawing.native xtd.core)

add_sources(
  "include/xtd/drawing/native/hdc_wrapper.hpp"
  "include/xtd/drawing/native/hdc_wrapper"
  "include/xtd/drawing/native/wx_application.hpp"
  "include/xtd/drawing/native/wx_application"
  "include/xtd/drawing/native/wx_brush.hpp"
  "include/xtd/drawing/native/wx_brush"
  "include/xtd/drawing/native/wx_pen.hpp"
  "include/xtd/drawing/native/wx_pen"
  "include/xtd/drawing/native/wxConicalGradient.hpp"
  "include/xtd/drawing/native/wxConicalGradient"
  "include/xtd/drawing/native/wxDrawString.hpp"
  "include/xtd/drawing/native/wxDrawString"
  "include/xtd/xtd.drawing.native.wxwidgets.hpp"
  "include/xtd/xtd.drawing.native.wxwidgets"
)
add_sources(
  "src/xtd/drawing/native/wxwidgets/brush.cpp"
  "src/xtd/drawing/native/wxwidgets/font.cpp"
  "src/xtd/drawing/native/wxwidgets/font_family.cpp"
  "src/xtd/drawing/native/wxwidgets/graphics.cpp"
  "src/xtd/drawing/native/wxwidgets/graphics_path.cpp"
  "src/xtd/drawing/native/wxwidgets/icon.cpp"
  "src/xtd/drawing/native/wxwidgets/image.cpp"
  "src/xtd/drawing/native/wxwidgets/matrix.cpp"
  "src/xtd/drawing/native/wxwidgets/pen.cpp"
  "src/xtd/drawing/native/wxwidgets/region.cpp"
  "src/xtd/drawing/native/wxwidgets/system_colors.cpp"
  "src/xtd/drawing/native/wxwidgets/system_images.cpp"
  "src/xtd/drawing/native/wxwidgets/system_images_gtk.cpp"
  "src/xtd/drawing/native/wxwidgets/system_fonts.cpp"
  "src/xtd/drawing/native/wxwidgets/toolkit.cpp"
)
if (APPLE)
  add_sources(
    "src/xtd/drawing/native/wxwidgets/system_colors.mm"
    "src/xtd/drawing/native/wxwidgets/system_images.mm"
  )
endif()
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
