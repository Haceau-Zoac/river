#ifndef RIVER_WINDOW_CLASS_H
#define RIVER_WINDOW_CLASS_H

#include <Windows.h> 

namespace river {
class window_class {
  WNDCLASSW wc_{};
  public:
  using procedure_t = WNDPROC;
  window_class(wchar_t const* name);

  auto set_procedure(procedure_t proc) -> void;
  auto class_name() const -> wchar_t const*;
  auto reg(void) -> void;
};
}

#endif // RIVER_WINDOW_CLASS_H
