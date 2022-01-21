#include "window_class.h"

namespace river {
window_class::window_class( wchar_t const* name) {
  wc_.lpszClassName = name;
  wc_.hInstance = GetModuleHandleW(nullptr);
}

auto window_class::set_procedure(window_class::procedure_t proc) -> void {
  wc_.lpfnWndProc = proc;
}

auto window_class::class_name() const -> wchar_t const* {
  return wc_.lpszClassName;
}

auto window_class::reg() -> void {
  RegisterClassW(&wc_);
}
}
