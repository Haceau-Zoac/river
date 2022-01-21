#ifndef RIVER_DEVICE_CONTEXT_H
#define RIVER_DEVICE_CONTEXT_H

#include "brush.h"
#include "type.h"
#include "window.h"
#include <Windows.h>

namespace river {
class device_context {
  public:
  using dc_handle_t = HDC;

  device_context(window const& win);
  device_context(window::window_handle_t const& win);
  device_context(device_context const&) = delete;
  device_context& operator=(device_context const&) = delete;
  ~device_context();

  auto paint_rectangle() -> rectangle&;
  auto fill(rectangle& rect, brush brush) -> void;

  protected:
  PAINTSTRUCT ps_;
  dc_handle_t dc_;
  window win_;
};
}

#endif // RIVER_DEVICE_CONTEXT_H
