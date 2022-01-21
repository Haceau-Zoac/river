#ifndef RIVER_WINDOW_H
#define RIVER_WINDOW_H

#include <optional>
#include <Windows.h>
#include "window_class.h"

namespace river {
enum class window_style {
  overlapped_window = WS_OVERLAPPEDWINDOW
};

struct window_config {
  window_class const* window_class;
  wchar_t const* text;
  window_style style;
};

class window {
  public:
  using window_handle_t = HWND;
  window(window_handle_t win);

  static auto create(window_config const& config) -> std::optional<window>;

  auto show() -> void;
  auto get() const -> window_handle_t;
  protected:
  window_handle_t hwnd_;
};
}

#endif // RIVER_WINDOW_H
