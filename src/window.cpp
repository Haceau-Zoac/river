#include "window.h"

namespace river {
window::window(window::window_handle_t win) : hwnd_(win) {}

auto window::create(const window_config &config) -> std::optional<window> {
  window::window_handle_t win{ CreateWindowExW(0,
    config.window_class->class_name(), config.text, static_cast<int>(config.style),
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    nullptr, nullptr, GetModuleHandleW(nullptr), nullptr)
  };
  if (win == nullptr) {
    return std::nullopt;
  } else {
    return window(win);
  }
}

auto window::show() -> void {
  ShowWindow(hwnd_, SW_SHOW);
}

auto window::get() const -> window_handle_t {
  return hwnd_;
}
}
